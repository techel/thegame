#pragma once

#include <sfml/Graphics/View.hpp>
#include <sfml/Graphics/RenderTarget.hpp>

//
// selects the given view into a render target. On destruction, the previous view is reset.
//

class ViewGuard
{
public:
	ViewGuard(const sf::View &view, sf::RenderTarget &target) : View(target.getView()), Target(target)
	{
		target.setView(view);
	}

	~ViewGuard()
	{
		Target.setView(View);
	}

private:
	const sf::View View;
	sf::RenderTarget &Target;
};