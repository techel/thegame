#pragma once

#include <memory>

//
// clients may put a task into a queue which is about to be dispatched later.
//

class TaskQueue
{
public:
    TaskQueue() = default;

    template<class Func>
	void enqueue(Func func)
	{
        auto task = std::make_unique<Task<Func>>(std::move(func));

        if(LastTask)
        {
            LastTask->NextTask = std::move(task);
            LastTask = LastTask->NextTask.get();
        }
        else
        {
            FirstTask = std::move(task);
            LastTask = FirstTask.get();
        }
	}

	bool dispatchSingle()
	{
        if(!FirstTask)
            return false;

        if(LastTask == FirstTask.get())
            LastTask = nullptr;

        auto task = std::move(FirstTask);
        FirstTask = std::move(task->NextTask);

        task->dispatch();
        return true;
	}

    void dispatchAll()
    {
        while(dispatchSingle());
    }

private:
	struct ITask
    {
        virtual ~ITask() = default;
        virtual void dispatch() = 0;

        std::unique_ptr<ITask> NextTask;
    };

    template<class F>
    struct Task : public ITask
    {
        F Func;
        Task(F f) : Func(std::move(f)) {}

        void dispatch() override
        {
            std::invoke(Func);
        }
    };

    std::unique_ptr<ITask> FirstTask;
    ITask *LastTask = nullptr;
};