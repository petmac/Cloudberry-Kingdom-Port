#ifndef ESCALATION_TUTORIAL
#define ESCALATION_TUTORIAL

#include <global_header.h>

namespace CloudberryKingdom
{
	class GUI_Text;
}

namespace CloudberryKingdom
{
	class Challenge_Escalation;
}



namespace CloudberryKingdom
{
	class Escalation_Tutorial : public GameObject
	{
	private:
		class ConfigureSongsHelper : public Lambda
		{
		public:
			void Apply();
		};

	private:
		class PreventThingsHelper : public Lambda
		{
		private:
			std::shared_ptr<Escalation_Tutorial> et;

		public:
			PreventThingsHelper( const std::shared_ptr<Escalation_Tutorial> &et );

			void Apply();
		};

	private:
		class TitleProxy : public Lambda
		{
		private:
			std::shared_ptr<Escalation_Tutorial> et;

		public:
			TitleProxy( const std::shared_ptr<Escalation_Tutorial> &et );

			void Apply();
		};

	private:
		class TutorialOrSkipProxy : public Lambda
		{
		private:
			std::shared_ptr<Escalation_Tutorial> et;

		public:
			TutorialOrSkipProxy( const std::shared_ptr<Escalation_Tutorial> &et );

			void Apply();
		};

	private:
		class NextTutorialHelper : public Lambda
		{
		private:
			std::shared_ptr<Escalation_Tutorial> et;
			std::shared_ptr<GUI_Text> text;

		public:
			NextTutorialHelper( const std::shared_ptr<Escalation_Tutorial> &et, const std::shared_ptr<GUI_Text> &text );

			void Apply();
		};

	private:
		class TextKillHelper : public Lambda
		{
		private:
			std::shared_ptr<Escalation_Tutorial> et;
			std::shared_ptr<GUI_Text> text;

		public:
			TextKillHelper( const std::shared_ptr<Escalation_Tutorial> &et, const std::shared_ptr<GUI_Text> &text );

			void Apply();
		};

	private:
		class ReadyProxy : public Lambda
		{
		private:
			std::shared_ptr<Escalation_Tutorial> et;

		public:
			ReadyProxy( const std::shared_ptr<Escalation_Tutorial> &et );

			void Apply();
		};

	private:
		class TutorialHelperReadyGo : public Lambda
		{
		private:
			std::shared_ptr<Escalation_Tutorial> et;

		public:
			TutorialHelperReadyGo( const std::shared_ptr<Escalation_Tutorial> &et );

			void Apply();
		};

	private:
		class EndProxy : public Lambda
		{
		private:
			std::shared_ptr<Escalation_Tutorial> et;

		public:
			EndProxy( const std::shared_ptr<Escalation_Tutorial> &et );

			void Apply();
		};

		/// <summary>
		/// Whether the Escalation introduction has been watched before.
		/// </summary>
	public:
		const static bool &getWatchedOnce();
		static void setWatchedOnce( const bool &value );
	private:
		static bool _WatchedOnce;

	public:
		static bool ShowTitle;

		/// <summary>
		/// Whether text makes a popping sound when we kill it
		/// </summary>
	protected:
		bool SoundOnKill;

	private:
		std::shared_ptr<Challenge_Escalation> Escalation;
	public:
		Escalation_Tutorial( const std::shared_ptr<Challenge_Escalation> &Escalation );

		virtual void OnAdd();

	protected:
		void TutorialOrSkip();

		virtual void Title();

	private:
		void Ready();

		void End();

	protected:
		virtual void MyPhsxStep();

	private:
		void InitializeInstanceFields();
	};
}


#endif	//#ifndef ESCALATION_TUTORIAL