#pragma once

#include <pu/Plutonium>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string>
#include <stdlib.h>
#include <filesystem>
#include "nfpemu.h"
#include "Amiibo.hpp"
#include "Utils.hpp"
#include "Settings.hpp"
#include "MainLayout.hpp"
#include "SettingsLayout.hpp"
#include "ErrorLayout.hpp"

namespace ui
{
	inline char* getExtension(const char* str)
	{
		const char* p;
		for (p = str+strlen(str); p >= str && *p != '.'; p--);
		return (char*)p;
	}

	class MainApplication : public pu::Application
	{
	    public:
	        MainApplication();
			MainLayout *GetMainLayout();
			SettingsLayout *GetSettingsLayout();
			ErrorLayout *GetErrorLayout();
			void SetWaitBack(bool state);
			void SetFooterText(std::string Text);
			void ShowError(std::string text);
	    private:
	        ui::MainLayout *mainLayout;
			ui::SettingsLayout *setLayout;
			ui::ErrorLayout *errorLayout;
			bool waitBack = false;
			pu::element::Image *logo;
			pu::element::Rectangle *header;
			pu::element::TextBlock *headerText;
			pu::element::Rectangle *footer;
			pu::element::TextBlock *footerText;
	};

	void SetMainApplication(MainApplication *MainApp);
	void Initialize();
	void Finalize();
}
