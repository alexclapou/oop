#include "test.h"
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

    date.tm_mday = 4;
    date.tm_mon = 12;
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

void to_string__valid_input__return_data_as_string()
{
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    assert(task.to_string() == "TITLE: abc TYPE: adea LAST PERFORMED DATE: 12-04-2012 TIME PERFORMED: 10 VISION: asd"); 
}

void test_task()
{
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
    to_string__valid_input__return_data_as_string();
}


void add__valid_task__task_added()
{
    DynamicVector<Task> dynamicvector;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("asdc", "asdc", date, 10, "123");
    assert(dynamicvector.add(task) == 1);
}

void remove__valid_task__task_removed()
{
    DynamicVector<Task> dynamicvector;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    dynamicvector.add(task);
    assert(dynamicvector.remove(0) == 1);
}

void update__valid_task__task_updated()
{
    DynamicVector<Task> dynamicvector;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    dynamicvector.add(task);
    date.tm_mday = 14;
    date.tm_mon = 1;
    date.tm_year = 2012;
    assert(dynamicvector.update(task, 0) == 1);
}

void search_task_title__valid_input__task_found()
{
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    repository.add(task);
    assert(repository.search_task_title("abc") == 0);
}

void search_task_title__valid_input__task_not_found()
{
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    repository.add(task);
    assert(repository.search_task_title("abcd") == -1);
}

void is_full__valid__true()
{
    DynamicVector<Task> dynamicvector;
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
    DynamicVector<Task> dynamicvector;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    dynamicvector.add(task);
    assert(dynamicvector.is_full() == false);
}

void length__valid__returned_length()
{
    DynamicVector<Task> dynamicvector;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    dynamicvector.add(task);
    assert(dynamicvector.length() == 1);
}

void resize__valid_input__size_changed()
{
    DynamicVector<Task> dynamicvector;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("abc", "adea", date, 10, "asd");
    dynamicvector.add(task);
    dynamicvector.add(task);
    dynamicvector.add(task);
    dynamicvector.add(task);
    dynamicvector.resize();
    assert(dynamicvector.is_full() == false);
}


void test_dynamicvector()
{
    add__valid_task__task_added();
    remove__valid_task__task_removed();
    update__valid_task__task_updated();
    is_full__valid__true();
    is_full__valid__false();
    length__valid__returned_length();
    resize__valid_input__size_changed();
}

void add__valid_input__task_added()
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

void update__valid_input__title_updated()
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

void update__valid_input__type_updated()
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

void update__valid_input__last_performed_day_updated()
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

void update__valid_input__last_performed_month_updated()
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

void update__valid_input__last_performed_year_updated()
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

void update__valid_input__times_performed_updated()
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

void update__valid_input__vision_updated()
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

void get_number_of_tasks__valid_input__number_of_task_returned()
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
    assert(repository.task_duplicate("asdc") == false);
}

void add_to_servant_list__valid_input__task_saved()
{
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("asd", "asd", date, 10, "asd");
    repository.add_to_servant_list(task);
    DynamicVector<Task> servant_list = repository.get_list_of_saved_tasks();
    assert(task == servant_list[0]);
}

void get_number_of_saved_tasks__valid_input__number_of_saved_tasks_returned()
{
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("asd", "asd", date, 10, "asd");
    repository.add_to_servant_list(task);
    repository.add_to_servant_list(task);
    repository.add_to_servant_list(task);
    repository.add_to_servant_list(task);
    assert(repository.get_number_of_saved_tasks() == 4);
}

void get_task__valid_input__task_passed()
{
    Repository repository;
    tm date;

    date.tm_mday = 4;
    date.tm_mon = 12;
    date.tm_year = 2012;
    Task task("asd", "asd", date, 10, "asd");
    repository.add(task);
    assert(task == repository.get_task(0));
}

void test_repository()
{
    add__valid_input__task_added();
    add_to_servant_list__valid_input__task_saved();
    remove__valid_input__task_removed();
    update__valid_input__task_updated();
    get_task__valid_input__task_passed();
    get_number_of_tasks__valid_input__number_of_task_returned();
    get_number_of_saved_tasks__valid_input__number_of_saved_tasks_returned();
    search_task_title__valid_input__task_found();
    search_task_title__valid_input__task_not_found();
    update__valid_input__title_updated();
    update__valid_input__type_updated();
    update__valid_input__last_performed_day_updated();
    update__valid_input__last_performed_month_updated();
    update__valid_input__last_performed_year_updated();
    update__valid_input__times_performed_updated();
    update__valid_input__vision_updated();
    task_duplicate__valid_title__task_found();
    task_duplicate__invalid_title__task_not_found();
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
    assert(service.remove("asdd") == 0);
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

void next__valid_input__next_task_returned()
{
    Service service;
    tm date;

    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;
    service.set_mode('A');
    service.add("b", "asd", date, 10, "asd");
    service.add("a", "asd", date, 10, "asd");
    service.set_mode('B');
    assert(service.next() == Task("b", "asd", date, 10, "asd"));
}


void next__valid_input__first_task_returned()
{
    Service service;
    tm date;

    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;
    service.set_mode('A');
    service.add("b", "asd", date, 10, "asd");
    service.add("a", "asd", date, 10, "asd");
    service.set_mode('B');
    service.next();
    assert(service.next() == Task("a", "asd", date, 10, "asd"));
}

void current_task__valid_input__return_current_saved_task()
{
    Service service;
    tm date;

    date.tm_mday = 3;
    date.tm_mon = 12;
    date.tm_year = 2010;
    service.set_mode('A');
    service.add("b", "asd", date, 10, "asd");
    service.set_mode('B');
    assert(service.current_task() == Task("b", "asd", date, 10, "asd"));
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
    next__valid_input__first_task_returned();
    next__valid_input__next_task_returned();
    current_task__valid_input__return_current_saved_task();
}

void all_tests()
{
    test_task();
    test_dynamicvector();
    test_repository();
    test_service();
 }
