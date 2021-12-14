#pragma once

#if !IL2CPP_THREADS_STD && IL2CPP_THREADS_WIN32

#include "os/ErrorCodes.h"
#include "os/Thread.h"
#include "os/WaitStatus.h"
#include "utils/NonCopyable.h"

#include "WindowsHeaders.h"

#define IL2CPP_DEFAULT_STACK_SIZE ( 1 * 1024 * 1024)			// default .NET stacksize is 1mb

namespace il2cpp
{
namespace os
{

class ThreadImpl : public il2cpp::utils::NonCopyable
{
public:
	ThreadImpl();
	~ThreadImpl();

	uint64_t Id ();
	ErrorCode Run (Thread::StartFunc func, void* arg);
	void SetName (const std::string& name);
	void SetPriority (ThreadPriority priority);
	
	void SetStackSize(size_t newsize)
	{
		// only makes sense if it's called BEFORE the thread has been created
		assert(m_ThreadHandle == NULL);
		// if newsize is zero we use the per-platform default value for size of stack
		if (newsize == 0)
		{
			newsize = IL2CPP_DEFAULT_STACK_SIZE;
		}
		m_StackSize = newsize;
	}
	
	void QueueUserAPC (Thread::APCFunc func, void* context);

	static void Sleep (uint32_t ms, bool interruptible);
	static uint64_t CurrentThreadId ();
	static ThreadImpl* CreateForCurrentThread ();

private:
	HANDLE m_ThreadHandle;
	DWORD m_ThreadId;
	SIZE_T m_StackSize;
};

}
}

#endif
