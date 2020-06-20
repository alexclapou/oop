#include <string>

class Astronomer{
    private:
        std::string name;
        std::string constellation;
    public:
        Astronomer(std::string _n, std::string _c):name{_n}, constellation{_c}{}
        std::string get_name();
        std::string get_constellation();

};

class Star{
    private:
        std::string name;
        std::string constellation;
        int ra;
        int dec;
        int diameter;
    public:
        Star(std::string _n, std::string _c, int _r, int _d, int _di):name{_n}, constellation{_c}, ra{_r}, dec{_d}, diameter{_di}{}
        std::string get_name();
        std::string get_constellation();
        int get_ra();
        int get_dec();
        int get_diameter(){
            return diameter;
        }
        friend std::ostream& operator<<(std::ostream& os, Star& star_to_add);
};
