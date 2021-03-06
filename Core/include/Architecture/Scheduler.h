/**
 * @file
 *
 * Multi-threaded job scheduler.
 */
#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

#include <ForwardDeclarations.h>

#ifdef CAFE
	#include "SchedulerWiiU.h"
#elif PS3
	#include "SchedulerPS3.h"
#elif VITA
	#include "SchedulerVita.h"
#else
	#include "SchedulerPc.h"
#endif

class Scheduler
{

	/// Platform specific implementation.
#ifdef CAFE
	SchedulerWiiU impl_;
#elif PS3
	SchedulerPS3 impl_;
#elif VITA
	SchedulerVita impl_;
#else
	SchedulerPc impl_;
#endif

private:

	/// No copying.
	Scheduler( const Scheduler & ) { }

	/// No assignment.
	Scheduler &operator = ( const Scheduler & ) { return *this; }

public:

	Scheduler() { }
	~Scheduler() { }

	/// Do processing that has to happen on the main thread.
	/**
	 * This method handles main thread jobs such as those needing to talk
	 * to the GPU.
	 */
	void MainThread()
	{
		impl_.MainThread();
	}

	/// Run a job in the background.
	/**
	 * @param job Pointer to job.  Scheduler takes ownership.
	 */
	void RunJob( Job *job )
	{
		impl_.RunJob( job );
	}

	/// Run a job as soon as possible.
	/**
	 * @param job Pointer to job.  Scheduler takes ownership.
	 */
	void RunJobASAP( Job *job )
	{
		impl_.RunJobASAP( job );
	}

	/// Create a resource.
	/**
	 * This method schedules the creation of a resource.  If the resource is
	 * loaded and created successfully, the given holder is updated to point
	 * to the resource.
	 *
	 * @param holder Pointer to holder that will receive updated resource.
	 * @param resource Resource to be loaded.
	 */
	void CreateResource( ResourceHolder *holder, Resource *resource )
	{
		impl_.CreateResource( holder, resource );
	}

	void CreateGpuResource( ResourceHolder *holder, Resource *resource )
	{
		impl_.CreateGpuResource( holder, resource );
	}
};

#endif
