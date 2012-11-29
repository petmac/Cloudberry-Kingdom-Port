#ifndef LEVELSEEDDATA
#define LEVELSEEDDATA

namespace CloudberryKingdom
{

	class LockableBool
	{
	public:
		Mutex MyMutex;

	private:
		bool _val;
	public:
		const bool &getval() const;
		void setval( const bool &value );

	private:
		void InitializeInstanceFields();

	public:
		LockableBool()
		{
			InitializeInstanceFields();
		}

	};

}

#endif	//#ifndef LEVELSEEDDATA