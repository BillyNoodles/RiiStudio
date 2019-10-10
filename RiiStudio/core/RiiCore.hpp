#pragma once

#include <LibRiiEditor/core/Applet.hpp>
#include <LibRiiEditor/ui/widgets/Dockspace.hpp>
#include "CoreContext.hpp"
#include "Theme.hpp"
#include <vector>
#include <string>
#include <LibRiiEditor/core/PluginFactory.hpp>

class RiiCore : public Applet
{
public:
	enum class OpenFilePolicy
	{
		NewEditor,
		ReplaceEditorIfMatching,
		ReplaceEditor
	};

	WindowContext makeWindowContext() override
	{
		return WindowContext(getSelectionManager(), mCoreRes);
	}

	void drawRoot() override;
	void drawMenuBar();
	std::vector<std::string> fileDialogueOpen();
	void openFile(OpenFilePolicy policy = OpenFilePolicy::NewEditor);

	RiiCore();
	~RiiCore();

private:
	DockSpace mDockSpace;
	Theme mTheme;
	EditorCoreRes mCoreRes = EditorCoreRes(mTheme);
	PluginFactory mPluginFactory;
};