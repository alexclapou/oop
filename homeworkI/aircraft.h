#include <string>
#include "exceptions.h"
#include <vector>

class Aircraft{
    protected:
        int id;
        std::string model;
        int maximum_altitude;
        std::vector<std::string> activities;
    public:
        Aircraft(int _id, std::string _model, int _maximum_altitude):id{_id}, model{_model}, maximum_altitude{_maximum_altitude}{}
        int get_maximum_altitute();
        std::string get_model();
        std::vector<std::string> get_activities();
};

class Helicopter:public Aircraft{
    private:
        int is_private;
    public:
        Helicopter(int _id, std::string _model, int _is_private, int _maximum_altitude):Aircraft{_id, _model, _maximum_altitude}, is_private{_is_private}{
            if(is_private == 1){
                activities.push_back("military");
                activities.push_back("medical emergencies");
                activities.push_back("public transportation");
                activities.push_back("leisure time");
            }
            if(maximum_altitude > 12)
                throw AircraftException(std::string("altitude too high"));
        }
};

class Plane:public Aircraft{
    private:
        int is_private;
        std::string main_wing;
    public:
        Plane(int _id, std::string _model, int _is_private, std::string _main_wing, int _maximum_altitude):Aircraft{_id, _model, _maximum_altitude}, is_private{_is_private}, main_wing{_main_wing}{
            if(main_wing == "biplane"){
                activities.push_back("military");
                activities.push_back("public transportation");
                activities.push_back("leisure time");
            }
            if(maximum_altitude > 26)
                throw AircraftException(std::string("altitude too high"));
        }
};

