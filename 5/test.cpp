#include "test.h"

void add__valid_task__task_added()
{
    DynamicVector dynamicvector;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("asdc", "asdc", date, 10, "123");
    assert(dynamicvector.add(task) == 1);
}
void remove__valid_task__task_removed()
{
    DynamicVector dynamicvector;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    dynamicvector.add(task);
    assert(dynamicvector.remove("abc") == 1);
}

void update__valid_task__task_updated()
{
    DynamicVector dynamicvector;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    dynamicvector.add(task);
    date.tm_mday = 14;
    date.tm_mon = 1;
    date.tm_year = 2012;
    assert(dynamicvector.update("abc", "AAAAAAAA", date, 10, "acD") == 1);
}

void search__valid_input__task_found()
{
    DynamicVector dynamicvector;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    dynamicvector.add(task);
    assert(dynamicvector.search("abc") == 0);
}

void search__valid_input__task_not_found()
{
    DynamicVector dynamicvector;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    dynamicvector.add(task);
    assert(dynamicvector.search("abcd") == -1);
}

void is_full__valid__true()
{
    DynamicVector dynamicvector;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    dynamicvector.add(task);
    dynamicvector.add(task);
    dynamicvector.add(task);
    dynamicvector.add(task);
    dynamicvector.add(task);
    assert(dynamicvector.is_full() == true);
}

void is_full__valid__false()
{
    DynamicVector dynamicvector;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    dynamicvector.add(task);
    assert(dynamicvector.is_full() == false);
}

void get_title__valid_input__task_passed()
{
    DynamicVector dynamicvector;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    dynamicvector.add(task);
    Task new_task;
    new_task = dynamicvector.get_task(0);
    assert(new_task.get_title() == task.get_title());
}
void get_type__valid_input__task_passed()
{
    DynamicVector dynamicvector;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    dynamicvector.add(task);
    Task new_task;
    new_task = dynamicvector.get_task(0);
    assert(new_task.get_type() == task.get_type());
}
void get_last_performed_day__valid_input__task_passed()
{
    DynamicVector dynamicvector;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    dynamicvector.add(task);
    Task new_task;
    new_task = dynamicvector.get_task(0);
    assert(new_task.get_last_performed_day() == task.get_last_performed_day());
}
void get_last_performed_month__valid_input__task_passed()
{
    DynamicVector dynamicvector;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    dynamicvector.add(task);
    Task new_task;
    new_task = dynamicvector.get_task(0);
    assert(new_task.get_last_performed_month() == task.get_last_performed_month());
}
void get_last_performed_year__valid_input__task_passed()
{
    DynamicVector dynamicvector;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    dynamicvector.add(task);
    Task new_task;
    new_task = dynamicvector.get_task(0);
    assert(new_task.get_last_performed_year() == task.get_last_performed_year());
}
void get_times_performed__valid_input__task_passed()
{
    DynamicVector dynamicvector;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    dynamicvector.add(task);
    Task new_task;
    new_task = dynamicvector.get_task(0);
    assert(new_task.get_times_performed() == task.get_times_performed());
}
void get_vision__valid_input__task_passed()
{
    DynamicVector dynamicvector;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    dynamicvector.add(task);
    Task new_task;
    new_task = dynamicvector.get_task(0);
    assert(new_task.get_vision() == task.get_vision());
}

void length__valid__returned_length()
{
    DynamicVector dynamicvector;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    dynamicvector.add(task);
    assert(dynamicvector.length() == 1);
}
void test_dynamicvector()
{
    get_title__valid_input__task_passed();
    get_type__valid_input__task_passed();
    get_last_performed_day__valid_input__task_passed();
    get_last_performed_month__valid_input__task_passed();
    get_last_performed_year__valid_input__task_passed();
    get_vision__valid_input__task_passed();
    get_times_performed__valid_input__task_passed();
    update__valid_task__task_updated();
    search__valid_input__task_found();
    search__valid_input__task_not_found();
    is_full__valid__true();
    is_full__valid__false();
    length__valid__returned_length();
}
void add_valid_input__task_added()
{
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task new_task("asd", "aasd", date, 10, "asd");
    assert(repository.add(new_task) == 1);
}

void remove__valid_input__task_removed()
{
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task new_task("asd", "asd", date, 10, "asd");
    repository.add(new_task);
    assert(repository.remove("asd") == 1);
}

void update__valid_input__task_updated()
{
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task new_task("asd", "asd", date, 10, "asd");
    repository.add(new_task);
    assert(repository.update("asd", "nou asd", date, 11, "nou asd") == 1);
}
void update_title__valid_input__title_updated()
{
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task new_task("asd", "asd", date, 10, "asd");
    repository.add(new_task);
    repository.update("asd", "nou asd", date, 11, "nou asd");
    assert(repository.get_task(0).get_title() == "asd");
}
void update_type__valid_input__type_updated()
{
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task new_task("asd", "asd", date, 10, "asd");
    repository.add(new_task);
    repository.update("asd", "nou asd", date, 11, "nou asd");
    assert(repository.get_task(0).get_type() == "nou asd");
}
void update_last_performed_day__valid_input__last_performed_day_updated()
{
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task new_task("asd", "asd", date, 10, "asd");
    repository.add(new_task);
    date.tm_mday = 23;
    repository.update("asd", "nou asd", date, 11, "nou asd");
    assert(repository.get_task(0).get_last_performed_day() == 23);
}
void update_last_performed_month__valid_input__last_performed_month_updated()
{
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task new_task("asd", "asd", date, 10, "asd");
    repository.add(new_task);
    date.tm_mon = 1;
    repository.update("asd", "nou asd", date, 11, "nou asd");
    assert(repository.get_task(0).get_last_performed_month() == 1);
}
void update_last_performed_year__valid_input__last_performed_year_updated()
{
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task new_task("asd", "asd", date, 10, "asd");
    repository.add(new_task);
    date.tm_year = 2020;
    repository.update("asd", "nou asd", date, 11, "nou asd");
    assert(repository.get_task(0).get_last_performed_year() == 2020);
}
void update_times_performed__valid_input__times_performed_updated()
{
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task new_task("asd", "asd", date, 10, "asd");
    repository.add(new_task);
    date.tm_mon = 11;
    repository.update("asd", "nou asd", date, 11, "nou asd");
    assert(repository.get_task(0).get_times_performed() == 11);
}
void update_vision__valid_input__vision_updated()
{
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task new_task("asd", "asd", date, 10, "asd");
    repository.add(new_task);
    repository.update("asd", "nou asd", date, 11, "nou asd");
    assert(repository.get_task(0).get_vision() == "nou asd");
}

void get_number_of_tasks__valkd_input__number_of_task_returned()
{
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task new_task("asd", "asd", date, 10, "ads");
    repository.add(new_task);
    repository.add(new_task);
    repository.add(new_task);
    repository.add(new_task);
    assert(repository.get_number_of_tasks() == 4);
}

void task_duplicate__valid_title__task_found()
{
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("asd", "asd", date, 10, "asd");
    repository.add(task);
    assert(repository.task_duplicate("asd") == true);
}

void task_duplicate__invalid_title__task_not_found()
{
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("asd", "asd", date, 10, "asd");

    repository.add(task);
    assert(repository.task_duplicate("asd") == true);
}

void test_repository()
{
    add_valid_input__task_added();
    remove__valid_input__task_removed();
    get_number_of_tasks__valkd_input__number_of_task_returned();
    update__valid_input__task_updated();
    update_title__valid_input__title_updated();
    update_type__valid_input__type_updated();
    update_last_performed_day__valid_input__last_performed_day_updated();
    update_last_performed_month__valid_input__last_performed_month_updated();
    update_last_performed_year__valid_input__last_performed_year_updated();
    update_times_performed__valid_input__times_performed_updated();
    update_vision__valid_input__vision_updated();
    task_duplicate__valid_title__task_found();
    task_duplicate__invalid_title__task_not_found();
    test_repository();
}
void set_mode__char_A__mode_true()
{
    Service service;

    service.set_mode('A');
    assert(service.get_mode() == true);
}

void set_mode__char_not_A__mode_false()
{
    Service service;

    service.set_mode('X');
    assert(service.get_mode() == false);
}

void add__task_duplicate__task_added()
{
    Service service;
    tm date;

    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;
    service.set_mode('A');
    assert(service.add("one", "two", date, 10, "three") == 1);
}

void add__task_duplicate__task_not_added()
{
    Service service;
    tm date;

    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;
    service.set_mode('A');
    service.add("one", "two", date, 10, "three");
    assert(service.add("one", "two", date, 10, "three") == 0);
}

void add__mode_not_A__task_not_added()
{
    Service service;
    tm date;

    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;
    assert(service.add("one", "two", date, 10, "three") == 0);
}

void update__mode_not_a__returned_0()
{
    Service service;
    tm date;
    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;

    service.set_mode('A');
    service.add("asd", "asd", date, 10, "asd");
    service.set_mode('X');
    assert(service.update("asd", "asdc", date, 123, "asd") == 0);
}

void update__task_found_mode_A__task_updated()
{
    Service service;
    tm date;
    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;

    service.set_mode('A');
    service.add("asd", "asd", date, 10, "asd");
    assert(service.update("asd", "asdc", date, 123, "asd") == 1);
}

void update__task_not_found__returned_0()
{
    Service service;
    tm date;

    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;
    service.set_mode('A');
    service.add("asd", "asd", date, 10, "asd");
    assert(service.update("asdasd", "asdc", date, 123, "asd") == 0);
}

void remove__task_not_found__returned_0()
{
    Service service;
    tm date;

    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;
    service.set_mode('A');
    service.add("asd", "asd", date, 10, "asd");
    assert(service.remove("qqqqq") == 0);
}

void remove__mode_not_A__returned_0()
{
    Service service;
    tm date;

    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;
    service.set_mode('A');
    service.add("asd", "asd", date, 10, "asd");
    service.set_mode('X');
    assert(service.remove("asd") == 0);
}

void remove__input_valid__task_removed()
{
    Service service;
    tm date;

    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;
    service.set_mode('A');
    service.add("asd", "asd", date, 10, "asd");
    assert(service.remove("asd") == 1);
}

void test_service()
{
    set_mode__char_A__mode_true();
    set_mode__char_not_A__mode_false();
    add__task_duplicate__task_not_added();
    add__mode_not_A__task_not_added();
    update__mode_not_a__returned_0();
    update__task_found_mode_A__task_updated();
    update__task_not_found__returned_0();
    remove__task_not_found__returned_0();
    remove__mode_not_A__returned_0();
    remove__input_valid__task_removed();
}
void all_tests()
{
    test_dynamicvector();
    test_repository();
    test_service();
}
