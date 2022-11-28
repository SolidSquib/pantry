#pragma once

#include "Renaissance/Core/Core.h"

using namespace Renaissance;

namespace Pantry
{
	class Panel
	{
	public:
		Panel(const String& name) : mName(name) { }
		virtual ~Panel() = default;

		virtual void Open() { }
		virtual void Close() { }

		virtual void OnUpdate(float deltaTime) { }
		virtual void OnUIRender() = 0;

		virtual bool WantsInputFocus() const { return false; }
		virtual bool WantsToClose() const = 0;

		// For serialization
		virtual String GetWindowClassName() const = 0;
		String GetWindowName() const { return mName; };

	protected:
		String mName;
	};
}