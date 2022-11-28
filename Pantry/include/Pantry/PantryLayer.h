#pragma once

#include "Renaissance/Core/Layer.h"

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

	};
}
