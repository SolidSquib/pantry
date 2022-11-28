#pragma once

#include "Renaissance/Core/Layer.h"
#include "Pantry/Panel.h"

namespace Pantry
{
	class PantryLayer : public Renaissance::Layer
	{
	public:
		void OnAttached() override;
		void OnDetached() override;
		void OnUpdate(float deltaTime) override;
		void OnUIRender() override;
		void OnEvent(Renaissance::Events::Event& e) override;

		template <typename T, typename ... Args>
		Renaissance::WeakPtr<T> CreateNewWindow(Args&& ... args)
		{
			Renaissance::SharedPtr<T> newWindow = MakeShared<T>(std::forward<Args>(args)...);
			mPanels.emplace_back(newWindow);
			newWindow->Open();
			return newWindow;
		}

		template <typename T>
		uint32_t GetWindowCount()
		{
			uint32_t count = 0;
			for (auto iter = mPanels.begin(); iter != mPanels.end(); ++iter)
			{
				if (std::dynamic_pointer_cast<T>(*iter))
				{
					count++;
				}
			}
			return count;
		}

		template <typename T>
		Renaissance::WeakPtr<T> GetWindow()
		{
			for (auto iter = mPanels.begin(); iter != mPanels.end(); ++iter)
			{
				if (Renaissance::SharedPtr<T> window = std::dynamic_pointer_cast<T>(*iter))
				{
					return window;
				}
			}
			return nullptr;
		}

	private:
		void CreateDefaultWindowLayout();

		bool mShowDemoWindow = false;
		std::vector<Renaissance::SharedPtr<Panel>> mPanels;
	};
}
