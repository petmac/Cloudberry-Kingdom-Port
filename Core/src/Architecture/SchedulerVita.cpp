#include <Architecture/SchedulerVita.h>

#include <Architecture/Job.h>
#include <Architecture/Scheduler.h>
#include <Content/Resource.h>
#include <Content/ResourcePtr.h>
#include <Core.h>
#include <Datastructures/Freelist.h>
#include <Utility/Log.h>

#include <iostream>

//#include <pthread.h>
//#include <semaphore.h>
//#include <sys/ppu_thread.h>

#define NUM_THREADS 1
#define MAIN_QUEUE_SIZE 6

/**
 * Load a resource.
 */
class ResourceLoaderJob : public Job
{

	ResourceHolder *holder_;
	Resource *resource_;
	bool gpuCreate_;

public:

	ResourceLoaderJob() :
		holder_( 0 ),
		resource_( 0 ),
		gpuCreate_( false )
	{
	}

	ResourceLoaderJob( ResourceHolder *holder, Resource *resource, bool gpuCreate ) :
		holder_( holder ),
		resource_( resource ),
		gpuCreate_( gpuCreate )
	{
	}

	void Do()
	{
		resource_->Load();

		// If there is an error, stop.
		if( !resource_->IsLoaded() )
		{
			LOG_WRITE( "Failed: %s\n", resource_->GetPath().c_str() );
			return;
		}

		LOG_WRITE( "Loaded: %s\n", resource_->GetPath().c_str() );

		// Kick off a creation job.
		if( gpuCreate_ )
		{
			SCHEDULER->CreateGpuResource( holder_, resource_ );
		}
	}

};

/**
 * Create a resource.
 */
class ResourceCreatorJob : public Job
{

	ResourceHolder *holder_;
	Resource *resource_;

public:

	ResourceCreatorJob( ResourceHolder *holder, Resource *resource ) :
		holder_( holder ),
		resource_( resource )
	{
	}

	void Do()
	{
		resource_->GpuCreate();
		holder_->SetResource( resource_ );
	}

};

struct SchedulerInternal
{
	//pthread_t Threads[ NUM_THREADS ];
	bool WorkersRunning;

	std::list< Job * > JobQueue;
	//pthread_mutex_t JobQueueMutex;
	//sem_t JobQueueSemaphore;

	std::list< Job * > MainThreadJobQueue;
	//pthread_mutex_t MainThreadJobQueueMutex;
	//sem_t MainThreadSemaphore;
};

static void *ThreadProc( void *context )
{
	SchedulerVita *scheduler = reinterpret_cast< SchedulerVita * >( context );
	scheduler->WorkerThread();

	return NULL;
}

//static pthread_mutex_t gPauseMutex;

SchedulerVita::SchedulerVita() :
	internal_( new SchedulerInternal )
{
	internal_->WorkersRunning = true;

	//int ret = pthread_mutex_init( &internal_->JobQueueMutex, NULL );
	//assert( !ret );

	//ret = sem_init( &internal_->JobQueueSemaphore, 0, 0 );
	//assert( !ret );

	//ret = pthread_mutex_init( &internal_->MainThreadJobQueueMutex, NULL );
	//assert( !ret );

	//ret = sem_init( &internal_->MainThreadSemaphore, 0, MAIN_QUEUE_SIZE );
	//assert( !ret );

	//for( int i = 0; i < NUM_THREADS; ++i )
	//{
		//ret = pthread_create( &internal_->Threads[ i ], NULL, ThreadProc, this );
		//assert( !ret );

		//sched_param priorityParam;
		//priorityParam.sched_priority = 1001;
		//pthread_setschedparam( internal_->Threads[ i ], SCHED_FIFO, &priorityParam ); 
	//}

	//ret = pthread_mutex_init( &gPauseMutex, NULL );
	//assert( !ret );
}

class PauseSchedulerJob : public Job
{
public:

	void Do()
	{
		// Try to acquire and release the pause mutex.  The main thread
		// should be holding it to keep the pause job from finishing.
		//pthread_mutex_lock( &gPauseMutex );
		//pthread_mutex_unlock( &gPauseMutex );
	}
};

void PauseScheduler()
{
	// If the mutex is already locked it is likely the scheduler is already paused.
	//if( pthread_mutex_trylock( &gPauseMutex ) == 0 )
	{
		SCHEDULER->RunJobASAP( new PauseSchedulerJob );
	}
}

void ResumeScheduler()
{
	//pthread_mutex_unlock( &gPauseMutex );
}

class ExitSchedulerJob : public Job
{
public:

	void Do()
	{
		//pthread_exit( NULL );
	}
};

SchedulerVita::~SchedulerVita()
{
	// Resume scheduler in case it's paused.
	ResumeScheduler();

	internal_->WorkersRunning = false;

	RunJobASAP( new ExitSchedulerJob );

	std::list< Job * >::iterator i;
	for( i = internal_->JobQueue.begin(); i != internal_->JobQueue.end(); ++i )
		delete *i;

	delete internal_;
}

void SchedulerVita::MainThread()
{
	//pthread_mutex_lock( &internal_->MainThreadJobQueueMutex );
	while( internal_->MainThreadJobQueue.size() != 0 )
	{
		Job *job = internal_->MainThreadJobQueue.front();
		internal_->MainThreadJobQueue.pop_front();

		job->Do();
		delete job;

		//sem_post( &internal_->MainThreadSemaphore );
	}
	//pthread_mutex_unlock( &internal_->MainThreadJobQueueMutex );
}

void SchedulerVita::RunJob( Job *job )
{
	//pthread_mutex_lock( &internal_->JobQueueMutex );
	internal_->JobQueue.push_back( job );
	//pthread_mutex_unlock( &internal_->JobQueueMutex );
	//sem_post( &internal_->JobQueueSemaphore );
}

static void RunJobASAPThread( /*uint64_t*/ long long context )
{
	Job *job = reinterpret_cast< Job * >( context );

	job->Do();
	delete job;
}

void SchedulerVita::RunJobASAP( Job *job )
{
	//pthread_mutex_lock( &internal_->JobQueueMutex );
	internal_->JobQueue.push_front( job );
	//pthread_mutex_unlock( &internal_->JobQueueMutex );
	//sem_post( &internal_->JobQueueSemaphore );
}

void SchedulerVita::CreateResource( ResourceHolder *holder, Resource *resource )
{
	resource->Load();

	// If there is an error, stop.
	if( !resource->IsLoaded() )
	{
		LOG_WRITE( "Failed: %s\n", resource->GetPath().c_str() );
		return;
	}

	LOG_WRITE( "Loaded: %s\n", resource->GetPath().c_str() );

	resource->GpuCreate();
	holder->SetResource( resource );
	//ResourceLoaderJob *job = new ResourceLoaderJob( holder, resource, true );

	//pthread_mutex_lock( &internal_->JobQueueMutex );
	//internal_->JobQueue.push_back( job );
	//pthread_mutex_unlock( &internal_->JobQueueMutex );
	//sem_post( &internal_->JobQueueSemaphore );
}

void SchedulerVita::CreateGpuResource( ResourceHolder *holder, Resource *resource )
{
	ResourceCreatorJob *job = new ResourceCreatorJob( holder, resource );

	//sem_wait( &internal_->MainThreadSemaphore );

	//pthread_mutex_lock( &internal_->MainThreadJobQueueMutex );
	internal_->MainThreadJobQueue.push_back( job );
	//pthread_mutex_unlock( &internal_->MainThreadJobQueueMutex );
}

void SchedulerVita::WorkerThread()
{
	while( internal_->WorkersRunning )
	{
		//sem_wait( &internal_->JobQueueSemaphore );

		Job *job = NULL;
		//pthread_mutex_lock( &internal_->JobQueueMutex );
		if( !internal_->JobQueue.empty() )
		{
			job = internal_->JobQueue.front();
			internal_->JobQueue.pop_front();
		}
		//pthread_mutex_unlock( &internal_->JobQueueMutex );

		if( !job )
			continue;

		job->Do();
		delete job;
	}
}
