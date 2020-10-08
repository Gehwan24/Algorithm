import requests
import time
import numpy as np

url = 'https://pegkq2svv6.execute-api.ap-northeast-2.amazonaws.com/prod/users'  #로컬호스트 연결

truck_num = 10
pan_size = 60
located_bikes = 3
pan = np.full((pan_size, pan_size), located_bikes)
# start 함수
# user_key : 토큰으로 받은 user의 키
# probel_id : 문제 번호
def start(problem_id,token): 
    uri = url+"/start"
    return requests.post(uri,headers={'X-Auth-Token':token},json={"problem": 1}).json()

# oncalls 토큰 호출 방법
# return 값 : 토큰
#
def location(token):
    uri = url+'/locations'
    return requests.get(uri, headers={'Authorization':token}).json()

def truck_position(token):
    uri = url+'/trucks'
    return requests.get(uri, headers={'Authorization':token}).json()

def simulate(token,commands):
    uri = url+'/simulate'
    return requests.put(uri, headers={'Authorization':token},json={'commands':commands}).json()

def get_score(token):
    uri = url+'/score'
    return requests.get(uri, headers={'Authorization':token}).json()
        


class Truck():               # 트럭 생성
    def __init__(self):
        self.index = 0
        self.commands = []
        self.load_bikes = 0
        self.is_load = False #적재했을 경우, 자전거를 놓으러 가고, 적재하지 않을 경우 자전거를 실으러 감
        self.second = 0
        self.dest_index = 0 # 도착지점 맨 처음 시작 때는 각 위치로 먼저 이동시킬 것이며, 
                            # 이후에는 각 구역에서 가장 적은 자전거가 존재하는 곳에 자전거를 놓으러 가는 역할 

    def put_down(self) : 
        while len(self.commands) < 10 and pan[self.index % pan_size][self.index // pan_size] > located_bikes : 
            self.commands.append(6)
            self.second+=6
            pan[self.index % pan_size][self.index // pan_size] -= 1

    def put_up(self) :
        
        while len(self.commands) < 10 and pan[self.index % pan_size][self.index // pan_size] < located_bikes : 
            self.commands.append(6)
            self.second+=6
            pan[self.index % pan_size][self.index // pan_size] += 1
    def move(self,x,y) :
        while self.second != 60 and x != 0 : # x가 0이 아니고 시간이 안지났을 경우
            if(x > 0) : #x가 0보다 클때 -> 목표값이 큰 위치일 때 
                self.index+=1 # 위로 이동
                self.commands.append(1)
                x-=1 
            else :
                self.index-=1
                self.commands.append(3) #아래로 이동
                x+=1
            self.second+=6

        while self.second != 60 and y != 0 : # x가 0이 아니고 시간이 안지났을 경우
            if(y > 0) : #y가 0보다 클때 -> 목표값이 오른쪽 위치일 때 
                self.index+= pan_size # 위로 이동
                y-=1
                self.commands.append(2) 
            else :
                self.index-= pan_size
                y += 1
                self.commands.append(4) #아래로 이동
            self.second+=6

    def find_many_bike_in_this_section(self) : #각 섹션의 최대값 찾기
        smallest = pan[0][0]
        index = [0,0]
        for i in range(pan_size) : 
            for j in range(self.dest_index // pan_size+1):
                if smallest > pan[i][j] : 
                    smallest = pan[i][j]
                    index = [i,j]
        self.dest_index = j*pan_size + i
            

    def find_less_bike_in_this_section(self) : # 각 섹션 최소값 찾기
        smallest = pan[0][0]
        index = [0,0]
        for i in range(pan_size) : 
            for j in range(self.dest_index // pan_size+1):
                if smallest < pan[i][j] : 
                    smallest = pan[i][j]
                    index = [i,j]
        self.dest_index = j*pan_size + i

    def decide(self):
        if self.load_bikes == 0 : 
            self.find_many_bike_in_this_section()
        else :
            self.find_less_bike_in_this_section()
        if self.index != self.dest_index :  #인덱스가 시작하는 곳과 끝나는 곳이 다를 경우
            tx = self.dest_index % pan_size - self.index % pan_size  
            ty = self.dest_index // pan_size - self.index // pan_size
            self.move(tx,ty) # 이동을 판단하는 함수이용
            if pan[self.index % pan_size][self.index // pan_size] > located_bikes and self.load_bikes < 20:
                self.put_up() #현재 위치에 자전거를 확인하고 계속 실는다
            if pan[self.index % pan_size][self.index // pan_size] < located_bikes and self.load_bikes > 0 :
                self.put_down() #현재 위치에 자전거를 확인하고 계속 놓아준다    
       

            
if __name__ == '__main__':
    # API START
    start_ret = start(2,"20a66301841d0b9afce6e96dccddcdbb")
    token = start_ret['auth_key'] #api token key
    trucks = [Truck() for _ in range(truck_num)]
    for i in range(len(trucks)) :
        trucks[i].dest_index = i*pan_size + pan_size-1 if i%2 == 1 else 0  
   # while True :
    commands = []
    for i in range(len(trucks)) :
        commands.append({'truck_id' : i, 'command':trucks[i].commands})
    while True :
        locate = location(token)

        for i in locate['locations'] :
            pan[i['id']%pan_size][i['id']//pan_size] = i['located_bikes_count']
      
        trucks_command = truck_position(token)
         
        for i in trucks_command['trucks'] : 
            trucks[i['id']].index = i['location_id']
            trucks[i['id']].load_bikes = i['loaded_bikes_count']

        for i in range(len(trucks)) :
            trucks[i].decide()   

        simul = simulate(token,commands)
        print(simul)
        if simul['status']== "finished" : break

    print(get_score(token))

        