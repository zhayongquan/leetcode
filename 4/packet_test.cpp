#include<iostream>
#include<vector>

class Solution{
public:
    std::vector<int >CurrentPacketMIs;
    std::vector<std::vector<int >>finalPacket;
    int packetInsNum = 2;
    void dump(int val){
        if(CurrentPacketMIs.size() < packetInsNum ){
            CurrentPacketMIs.push_back(val);
            if(CurrentPacketMIs.size() == packetInsNum){
                finalPacket.push_back(CurrentPacketMIs);
                CurrentPacketMIs.clear();
            }
            return;
        }
    }
};

int main(){
    Solution sol;
    for(int i = 0; i < 10; i++){
        sol.dump(i);
    }
    for(auto it = sol.finalPacket.begin(); it != sol.finalPacket.end(); it++){
        for(auto jt = (*it).begin(); jt!= (*it).end(); jt++){
            std::cout<<"jt :"<<*jt<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}