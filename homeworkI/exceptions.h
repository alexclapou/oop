 #include <string>
 class AircraftException {
     private:
         std::string error_message;
     public:
         AircraftException(std::string _error_message);
         const char* what()const noexcept;
 };
