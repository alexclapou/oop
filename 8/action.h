#pragma once
#include "repository.h"
#include <memory>
class Action{
    protected:
        Repository *repository;
    public:
        Action(Repository *_repository):repository{_repository}{}
        Action(){}
        virtual void undo() = 0;
        virtual void redo() = 0;
};

class ActionAdd:public Action{
    private:
        Task added_task;
    public:
        ActionAdd(Repository *_repository, Task _added_task):Action{_repository}, added_task{_added_task}{}
        void undo();
        void redo();
};

class ActionRemove:public Action{
    private:
        Task removed_task;
    public:
        ActionRemove(Repository *_repository, Task _removed_task):Action{_repository,},removed_task{_removed_task}{}
        void undo();
        void redo();
};

class ActionUpdate:public Action{
    private:
        Task old_updated_task;
        Task new_updated_task;
    public:
        ActionUpdate(Repository *_repository, Task _old, Task _new):Action{_repository}, old_updated_task{_old}, new_updated_task{_new}{}
        void undo();
        void redo();
};
