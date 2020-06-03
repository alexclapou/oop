#include <string.h>

class UserMessage{
};

class Message{
    private:
        tm time;
        std::string message;
    public:
        Message(tm _time, std::string _message):time{_time}, message{_message}{}
        tm get_time();
        std::string get_message();
}

:wq!
:wq!
:
