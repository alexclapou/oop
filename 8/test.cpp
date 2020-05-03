#include "test.h"
#include <fstream>
#include <vector>
void get_title__valid_input__task_passed()
{
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    assert(task.get_title() == "abc");
}

void get_type__valid_input__task_passed()
{
    tm date;

    date.tm_mday = 12;
    date.tm_mon = 5;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    assert(task.get_type() == "adea");
}

void get_last_performed_day__valid_input__task_passed()
{
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    assert(task.get_last_performed_day() == 4);
}

void get_last_performed_month__valid_input__task_passed()
{
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    assert(task.get_last_performed_month() == 12);
}

void get_last_performed_year__valid_input__task_passed()
{
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    assert(task.get_last_performed_year() == 2012);
}

void task__no_parameters__task_created()
{
    Task task;
    assert(task.get_times_performed() ==0);
}

void task_initialized__valid_input__task_initialized()
{
    Task init_task;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("a", "a", date, 10, "a");
    init_task = task;
    assert(init_task == task);
}

void get_times_performed__valid_input__task_passed()
{
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    assert(task.get_times_performed() == 10);
}

void get_vision__valid_input__task_passed()
{
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    assert(task.get_vision() == "asd");
}

void set_last_performed_day__valid_input__last_performed_day_updated()
{
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    task.set_last_performed_day(14);
    assert(task.get_last_performed_day() == 14);
}

void set_last_performed_month__valid_input__last_performed_month_updated()
{
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    task.set_last_performed_month(4);
    assert(task.get_last_performed_month() == 4);
}

void set_last_performed_year__valid_input__last_performed_year_updated()
{
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    task.set_last_performed_year(2020);
    assert(task.get_last_performed_year() == 2020);
}

void set_title__valid_input__title_updated()
{
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    task.set_title("new abc");
    assert(task.get_title() == "new abc");
}

void set_type__valid_input__type_updated()
{
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    task.set_type("new adea");
    assert(task.get_type() == "new adea");
}

void set_times_performed__valid_input__time_performed_updated()
{
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    task.set_times_performed(100);
    assert(task.get_times_performed() == 100);
}

void set_vision__valid_input__vision_updated()
{
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    task.set_vision("new abc");
    assert(task.get_vision() == "new abc");
}

void to_string__valid_input__return_data_as_string_two_digits_month_day()
{
    tm date;

    date.tm_mday = 12;
    date.tm_mon = 5;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    assert(task.to_string() == "TITLE: abc, TYPE: adea, LAST PERFORMED DATE: 05-12-2012, TIMES PERFORMED: 10, VISION: asd"); 
}


void to_string__valid_input__return_data_as_string_one_digit_month_day()
{
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    assert(task.to_string() == "TITLE: abc, TYPE: adea, LAST PERFORMED DATE: 12-04-2012, TIMES PERFORMED: 10, VISION: asd"); 
}

void test_task()
{
    task__no_parameters__task_created();
    get_title__valid_input__task_passed();
    get_type__valid_input__task_passed();
    get_last_performed_day__valid_input__task_passed();
    get_last_performed_month__valid_input__task_passed();
    get_last_performed_year__valid_input__task_passed();
    get_vision__valid_input__task_passed();
    get_times_performed__valid_input__task_passed();
    set_last_performed_day__valid_input__last_performed_day_updated();
    set_last_performed_month__valid_input__last_performed_month_updated();
    set_last_performed_year__valid_input__last_performed_year_updated();
    set_title__valid_input__title_updated();
    set_type__valid_input__type_updated();
    set_times_performed__valid_input__time_performed_updated();
    set_vision__valid_input__vision_updated();
    to_string__valid_input__return_data_as_string_one_digit_month_day();
    to_string__valid_input__return_data_as_string_two_digits_month_day();
    task_initialized__valid_input__task_initialized();
}


void search_task_title__valid_input__task_found()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Repository repository;
    tm date;

    repository.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    repository.add_file_data(task);
    assert(repository.search_task_title("abc") == 0);
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void search_task_title__valid_input__task_not_found()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    repository.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    repository.add_file_data(task);
    assert(repository.search_task_title("abcd") == -1);
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void add_file_data__valid_input__task_added()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    repository.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Task new_task("asd", "aasd", date, 10, "asd");
    repository.add_file_data(new_task);
    assert(repository.get_number_of_tasks() == 1);
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void remove_file_data__valid_input__task_removed()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    repository.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Task new_task("asd", "asd", date, 10, "asd");
    repository.add_file_data(new_task);
    Task new_task1("asdd", "asd", date, 10, "asd");
    repository.add_file_data(new_task1);
    repository.remove_file_data("asd");
    repository.remove_file_data("asdd");
    assert(repository.get_number_of_tasks() == 0);
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void update_file_data__valid_input__task_updated()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    repository.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Task new_task("asd", "asd", date, 10, "asd");
    repository.add_file_data(new_task);
    Task new_task1("asd", "asd", date, 10, "asd");
    repository.add_file_data(new_task1);
    assert(repository.update_file_data("asd", "nou asd", date, 11, "nou asd") == 1);
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void update_file_data__valid_input__title_updated()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task new_task("asd", "asd", date, 10, "asd");
    repository.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    repository.add_file_data(new_task);
    repository.update_file_data("asd", "nou asd", date, 11, "nou asd");
    assert(repository.get_task(0).get_title() == "asd");
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void update_file_data__valid_input__type_updated()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task new_task("asd", "asd", date, 10, "asd");
    repository.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    repository.add_file_data(new_task);
    repository.update_file_data("asd", "nou asd", date, 11, "nou asd");
    assert(repository.get_task(0).get_type() == "nou asd");
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void update_file_data__valid_input__last_performed_day_updated()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task new_task("asd", "asd", date, 10, "asd");
    repository.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    repository.add_file_data(new_task);
    date.tm_mday = 23;
    repository.update_file_data("asd", "nou asd", date, 11, "nou asd");
    assert(repository.get_task(0).get_last_performed_day() == 23);
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void update_file_data__valid_input__last_performed_month_updated()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task new_task("asd", "asd", date, 10, "asd");
    repository.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    repository.add_file_data(new_task);
    date.tm_mon = 1;
    repository.update_file_data("asd", "nou asd", date, 11, "nou asd");
    assert(repository.get_task(0).get_last_performed_month() == 1);
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void update_file_data__valid_input__last_performed_year_updated()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task new_task("asd", "asd", date, 10, "asd");
    repository.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    repository.add_file_data(new_task);
    date.tm_year = 2020;
    repository.update_file_data("asd", "nou asd", date, 11, "nou asd");
    assert(repository.get_task(0).get_last_performed_year() == 2020);
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void update_file_data__valid_input__times_performed_updated()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task new_task("asd", "asd", date, 10, "asd");
    repository.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    repository.add_file_data(new_task);
    date.tm_mon = 11;
    repository.update_file_data("asd", "nou asd", date, 11, "nou asd");
    assert(repository.get_task(0).get_times_performed() == 11);
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void update_file_data__valid_input__vision_updated()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task new_task("asd", "asd", date, 10, "asd");
    repository.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    repository.add_file_data(new_task);
    repository.update_file_data("asd", "nou asd", date, 11, "nou asd");
    assert(repository.get_task(0).get_vision() == "nou asd");
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void task_duplicate__valid_title__task_found()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("asd", "asd", date, 10, "asd");
    repository.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    repository.add_file_data(task);
    assert(repository.task_duplicate("asd") == true);
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void task_duplicate__invalid_title__task_not_found()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("asd", "asd", date, 10, "asd");
    repository.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    repository.add_file_data(task);
    assert(repository.task_duplicate("asdc") == false);
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void add_to_servant_list__valid_input__task_saved()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.csv");
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("asd", "asd", date, 10, "asd");
    repository.set_mylistpath("/home/alexclapou/fac/oop/folder cu spatii/test_file.csv");
    repository.add_to_servant_list(task);
    assert(repository.get_number_of_saved_tasks() == 1);
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.csv");
}



void get_task__valid_input__task_passed()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("asd", "asd", date, 10, "asd");
    repository.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    repository.add_file_data(task);
    Task task1("asd1", "asd", date, 10, "asd");
    repository.add_file_data(task1);
    assert(task1 == repository.get_task(1));
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void set_filepath__valid_input__filepath_set()
{
    Repository repository;

    repository.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    assert(repository.get_filepath() == "/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}
void test_repository()
{
    add_file_data__valid_input__task_added();
    remove_file_data__valid_input__task_removed();
    add_to_servant_list__valid_input__task_saved();
    update_file_data__valid_input__task_updated();
    update_file_data__valid_input__title_updated();
    update_file_data__valid_input__type_updated();
    update_file_data__valid_input__last_performed_day_updated();
    update_file_data__valid_input__last_performed_month_updated();
    update_file_data__valid_input__last_performed_year_updated();
    update_file_data__valid_input__times_performed_updated();
    update_file_data__valid_input__vision_updated();
    get_task__valid_input__task_passed();
    get_number_of_tasks__valid_input__number_of_task_returned();
    search_task_title__valid_input__task_found();
    search_task_title__valid_input__task_not_found();
    task_duplicate__valid_title__task_found();
    task_duplicate__invalid_title__task_not_found();
    set_filepath__valid_input__filepath_set();
}

void set_mode__char_A__mode_true()
{
    Service service;

    service.set_mode('A');
    assert(service.get_mode() == 1);
}

void set_mode__char_not_AB__mode_false()
{
    Service service;

    service.set_mode('X');
    assert(service.get_mode() == 0);
}

void set_mode__char_B__mode_true()
{
    Service service;

    service.set_mode('B');
    assert(service.get_mode() == -1);
}

void add__task_not_duplicate__task_not_added()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Service service;
    tm date;

    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;
    service.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    service.set_mode('A');
    service.add("one", "two", date, 10, "three");
    assert(service.get_number_of_tasks() == 1);
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void add__task_duplicate__task_not_added()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Service service;
    tm date;

    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;
    service.set_mode('A');
    service.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    service.add("one", "two", date, 10, "three");
    try{
        service.add("one", "two", date, 10, "three");
    }
    catch(...){
        assert(service.get_number_of_tasks() == 1);
    }
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void add__mode_not_A__task_not_added()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Service service;
    tm date;

    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;
    service.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    try{
        service.add("one", "two", date, 10, "three");
    }
    catch(...){
        assert(service.get_number_of_tasks() == 0);
    }
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void update__mode_not_a__returned_0()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Service service;
    tm date;
    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;

    service.set_mode('A');
    service.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    service.add("asd", "asd", date, 10, "asd");
    service.set_mode('X');
    try{
        service.update("asd", "asdc", date, 123, "asd");
    }
    catch(...){
        assert(service.current_task("asd").get_type() == "asd");
    }
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void update__task_found_mode_A__task_updated()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Service service;
    tm date;
    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;

    service.set_mode('A');
    service.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    service.add("asd", "asd", date, 10, "asd");
    assert(service.update("asd", "asdc", date, 123, "asd") == 1);
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void update__task_not_found__returned_0()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Service service;
    tm date;
    Task keep_task;

    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;
    service.set_mode('A');
    service.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    service.add("asd", "asd", date, 10, "asd");
    keep_task = service.current_task("asd");
    try{
        service.update("asdasd", "asdc", date, 123, "asd");
    }
    catch(...){
        assert(service.current_task("asd") == keep_task);
    }
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void remove__task_not_found__returned_0()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Service service;
    tm date;

    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;
    service.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    service.set_mode('A');
    service.add("asd", "asd", date, 10, "asd");
    try{
        service.remove("asdd");
    }
    catch(...){
        assert(service.get_number_of_tasks() == 1);
    }
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void remove__mode_not_A__returned_0()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Service service;
    tm date;

    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;
    service.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    service.set_mode('A');
    service.add("asd", "asd", date, 10, "asd");
    service.set_mode('X');
    try{
        service.remove("asd");
    }
    catch(...){
        assert(service.get_number_of_tasks() == 1);
    }
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void remove__input_valid__task_removed()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Service service;
    tm date;

    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;
    service.set_mode('A');
    service.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    service.add("asd", "asd", date, 10, "asd");
    assert(service.remove("asd") == 1);
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void next__valid_input__next_task_returned()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Service service;
    tm date;

    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;
    service.set_mode('A');
    service.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    service.add("b", "asd", date, 10, "asd");
    service.add("a", "asd", date, 10, "asd");
    service.set_mode('B');
    service.next();
    service.next();
    assert(service.next() == Task("b", "asd", date, 10, "asd"));
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}


void next__valid_input__first_task_returned()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Service service;
    tm date;

    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;
    service.set_mode('A');
    service.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    service.add("b", "asd", date, 10, "asd");
    service.add("a", "asd", date, 10, "asd");
    service.set_mode('B');
    service.next();
    assert(service.next() == Task("a", "asd", date, 10, "asd"));
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void current_task__invalid_input__return_empty_task()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Service service;
    tm date;

    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;
    service.set_mode('A');
    service.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    service.add("b", "asd", date, 10, "asd");
    service.set_mode('B');
    assert(service.current_task("q") != Task("b", "asd", date, 10, "asd"));
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void current_task__valid_input__return_current_saved_task()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Service service;
    tm date;

    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;
    service.set_mode('A');
    service.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    service.add("b", "asd", date, 10, "asd");
    service.set_mode('B');
    assert(service.current_task("b") == Task("b", "asd", date, 10, "asd"));
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void get_list_of_tasks__valid_input__list_of_task_returned()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Service service;
    std::vector<Task> tasks_saved;
    int index;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    index = 0;
    service.set_mode('A');
    Task task1("a", "aaa", date, 10, "aaa");
    Task task2("b", "bcc", date, 10, "bbb");
    Task task3("c", "ccc", date, 10, "ccc");
    service.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    service.add("a", "aaa", date, 10, "aaa");
    tasks_saved.push_back(task1);
    service.add("b", "bbb", date, 10, "bbb");
    tasks_saved.push_back(task2);
    service.add("c", "ccc", date, 10, "ccc");
    tasks_saved.push_back(task3);
    std::vector<Task> all_tasks = service.get_list_of_tasks();
    for(Task task:all_tasks){
        assert(task == tasks_saved[index]);
        index++;
    }
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void get_number_of_tasks__valid_input__number_of_task_returned()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Service service;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    service.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    service.set_mode('A');
    service.add("a", "aaa", date, 10, "aaa");
    service.add("b", "aaa", date, 10, "aaa");
    service.add("c", "aaa", date, 10, "aaa");
    service.add("d", "aaa", date, 10, "aaa");
    assert(service.get_number_of_tasks() == 4);
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void get_filepath__valid_input__filepath_returned()
{
    Service service;

    service.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    assert(service.get_filepath() == "/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void get_number_of_saved_tasks__valid_input__number_of_saved_tasks_returned()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.csv");
    Service service;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    service.set_mode('B');
    service.set_mylistpath("/home/alexclapou/fac/oop/folder cu spatii/test_file.csv");
    Task task("asd", "asd", date, 10, "asd");
    service.add_to_servant_list(task);
    Task task1("asd1", "asd", date, 10, "asd");
    service.add_to_servant_list(task1);
    Task task2("asd2", "asd", date, 10, "asd");
    service.add_to_servant_list(task2);
    Task task3("asd3", "asd", date, 10, "asd");
    service.add_to_servant_list(task3);
    assert(service.get_number_of_saved_tasks() == 4);
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.csv");
}

void add_to_servant_list__mode_NOT_B__task_not_added()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.html");
    tm date;
    Service service;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("a", "a", date, 10,"a");
    service.set_mylistpath("/home/alexclapou/fac/oop/folder cu spatii/test_file.html");
    try{
        service.add_to_servant_list(task);
    }
    catch(...){
        assert(service.get_number_of_saved_tasks() == 0);
    }
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.html");
}

void get_list_by_type_and_times_performed__valid_input__list_returned()
{
    std::ifstream fin("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    Service service;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    service.set_filepath("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
    service.set_mode('A');
    service.add("a", "aaa", date, 10, "aaa");
    service.add("b", "aaa", date, 10, "aaa");
    service.add("c", "acac", date, 10, "aaa");
    service.set_mode('B');
    std::vector<Task> new_tasks = service.get_list_by_type_and_times_performed("aaa", 100);
    assert(new_tasks.size() ==  2);
    fin.close();
    remove("/home/alexclapou/fac/oop/folder cu spatii/test_file.txt");
}

void test_service()
{
    current_task__invalid_input__return_empty_task();
    add__task_duplicate__task_not_added();
    set_mode__char_A__mode_true();
    set_mode__char_not_AB__mode_false();
    set_mode__char_B__mode_true();
    add__task_not_duplicate__task_not_added();
    add_to_servant_list__mode_NOT_B__task_not_added();
    add__mode_not_A__task_not_added();
    update__mode_not_a__returned_0();
    get_filepath__valid_input__filepath_returned();
    update__task_found_mode_A__task_updated();
    update__task_not_found__returned_0();
    remove__task_not_found__returned_0();
    remove__mode_not_A__returned_0();
    remove__input_valid__task_removed();
    next__valid_input__first_task_returned();
    next__valid_input__next_task_returned();
    get_list_by_type_and_times_performed__valid_input__list_returned();
    current_task__valid_input__return_current_saved_task();
    get_list_of_tasks__valid_input__list_of_task_returned();
    get_number_of_saved_tasks__valid_input__number_of_saved_tasks_returned();
}

void all_tests()
{
    test_task();
    test_repository();
   test_service();
 }
