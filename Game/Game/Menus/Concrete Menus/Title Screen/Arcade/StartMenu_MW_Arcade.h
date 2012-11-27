#ifndef STARTMENU_MW_ARCADE
#define STARTMENU_MW_ARCADE

#include <global_header.h>

namespace CloudberryKingdom
{
	class TitleGameData_MW;
}

namespace CloudberryKingdom
{
	class MenuItem;
}




namespace CloudberryKingdom
{
	class StartMenu_MW_Arcade : public ArcadeMenu
	{
	public:
		std::shared_ptr<TitleGameData_MW> Title;
		StartMenu_MW_Arcade( const std::shared_ptr<TitleGameData_MW> &Title );

		virtual void SlideIn( int Frames );

		virtual void SlideOut( const std::shared_ptr<PresetPos> &Preset, int Frames );

	protected:
		virtual void SetItemProperties( const std::shared_ptr<MenuItem> &item );

	public:
		virtual void Go( const std::shared_ptr<MenuItem> &item );

		virtual void OnAdd();

		virtual void Init();

	private:
		void SetPos();
	};
}


#endif	//#ifndef STARTMENU_MW_ARCADE