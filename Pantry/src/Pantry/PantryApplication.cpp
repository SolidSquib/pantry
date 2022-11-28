// Pantry.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "PantryPCH.h"

#include "Renaissance/Core/EntryPoint.h"
#include "Pantry/PantryLayer.h"

namespace Pantry
{
	class PantryApplication : public Renaissance::Application
	{
	public:
		PantryApplication(const std::string& name, Renaissance::ApplicationCommandLineArgs args)
			: Renaissance::Application(name, args)
		{
			mPantry = CreateNewLayer<PantryLayer>();
		}

	private:
		Renaissance::WeakPtr<PantryLayer> mPantry;
	};
}

namespace Renaissance
{
	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new Pantry::PantryApplication("Pantry", args);
	}
}