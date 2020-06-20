#include "widget.h"
#include <cassert>
#include <QDebug>
#include "repo.h"
#include <QApplication>
#include "model.h"

void add_star__ok_input__star_added(){
    Repository r{"astronomers.in", "stars.in"};
    int size = r.stars_size();
    assert(r.stars_size() == size);
    r.add_star(Star("ads", "asd", 4, 5,5));
    assert(r.stars_size() == size+1);
    r.add_star(Star("start", "asd", 5, 4,3));
    assert(r.stars_size() == size+2);
    r.add_star(Star("stt", "asd", 1, 3,2));
    assert(r.stars_size() == size+3);
}

void add_star__bad_input__star_not_added(){
    Repository r{"astronomers.in", "stars.in"};
    int q = r.stars_size();
    assert(r.stars_size() == q);
    r.add_star(Star("ads", "asd", 0, 1,3));
    assert(r.stars_size() == q);
    r.add_star(Star("", "asd", 4, 4, 4));
    assert(r.stars_size() == q);
    r.add_star(Star("ads", "asd", 1,0, 0));
    assert(r.stars_size() == q);
    r.add_star(Star("ads", "asd", 0, 0,0));
}

void test_add(){
    add_star__bad_input__star_not_added();
    add_star__ok_input__star_added();
}

int main(int argc, char *argv[])
{
    test_add();
    QApplication a(argc, argv);
    Repository r{"astronomers.in", "stars.in"};
    AstronomerModel *model = new AstronomerModel{r};
    auto astronomers = r.get_astronomers();
    for(auto astronomer:astronomers){
        Widget *w = new Widget{astronomer, model, r};
        w->show();
    }
    return a.exec();
}
