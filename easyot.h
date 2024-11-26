#include <list>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <nlohmann/json.hpp>
#include "httplib.h"
#ifndef EASYOT
#define EASYOT

using namespace std;

template <typename D>

class EasyOT{
    public:
        EasyOT(){}
        EasyOT(vector<string> labels) : label(labels), size(labels.size()){};
        void info(){
            cout << "Jumlah Labels : " << get_size() << endl;
            for(string label : get_label()){
                cout << label << endl;
            }
        }
        void send_data(D data[], int data_size, string url, string endpoint){
            map<string, D> datas = {};
            try{

                if(data_size != get_size()){
                    throw (data_size);
                }
                for(int i = 0; i < get_size(); i++){
                    datas[get_label().at(i)] = data[i];
                }

                for(auto& dat : datas){
                    cout << dat.first << " : " << dat.second << endl;
                }

                nlohmann::json j = datas;
                cout << j.dump(4) << endl;

                fetch(url, endpoint, j);
            }catch(int size){
                cout << "Data length must be equal to labels length" << endl;
                cout << "Data Length : " << data_size << endl;
                cout << "Labels Length : " << get_label().size() << endl;
            }
        };
        void add_label(list<string> labels){
            label = label;
        }
        int get_size() const{
            return size;
        }
    private:
        vector<string> label;
        size_t size;
        vector<string> get_label() const{
            return label;
        }

        void fetch(string url, string endpoint, nlohmann::json data){
            httplib::Client client(url);

            httplib::Headers headers = {
                {"Content-Type", "application/json"}
            };

            auto response = client.Post(endpoint, headers, data.dump(), "application/json");

            if (response && response->status == 200) {
                std::cout << "Response: " << response->body << std::endl;
            } else {
                std::cerr << "Failed to send request. Status: " 
                        << (response ? std::to_string(response->status) : "No Response") 
                        << std::endl;
            }
        }
};

#endif