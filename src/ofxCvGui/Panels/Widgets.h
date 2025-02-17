#pragma once

#include "Scroll.h"

#include "../Widgets/Title.h"
#include "../Widgets/Button.h"
#include "../Widgets/Toggle.h"
#include "../Widgets/Slider.h"
#include "../Widgets/EditableValue.h"

#define OFXCVGUI_PANELS_WIDGETS_MAKE_HEADER(T, ...) shared_ptr<ofxCvGui::Widgets::T> add(__VA_ARGS__)
#define OFXCVGUI_PANELS_WIDGETS_MAKE_BODY(T, ...) auto widget = ofxCvGui::Widgets::T::make(__VA_ARGS__); \
	this->add(widget); \
	return widget;
#define OFXCVGUI_PANELS_WIDGETS_MAKE_SIMPLE(T, ARGTYPE) OFXCVGUI_PANELS_WIDGETS_MAKE_HEADER(T, ARGTYPE parameter) { OFXCVGUI_PANELS_WIDGETS_MAKE_BODY(T, parameter) }

namespace ofxCvGui {
	namespace Panels {
		class Widgets : public Scroll {
		public:
			using Scroll::add;
			
			// Add Widgets::Title
			OFXCVGUI_PANELS_WIDGETS_MAKE_HEADER(Title, string caption, ofxCvGui::Widgets::Title::Level level) {
				OFXCVGUI_PANELS_WIDGETS_MAKE_BODY(Title, caption, level);
			}

			// Add Widgets::Title
			OFXCVGUI_PANELS_WIDGETS_MAKE_HEADER(Title, string caption) {
				OFXCVGUI_PANELS_WIDGETS_MAKE_BODY(Title, caption);
			}
			
			// Add Widgets::Button
			OFXCVGUI_PANELS_WIDGETS_MAKE_HEADER(Button, string caption, function<void()> action) {
				OFXCVGUI_PANELS_WIDGETS_MAKE_BODY(Button, caption, action);
			}
			
			// Add Widgets::Slider
			OFXCVGUI_PANELS_WIDGETS_MAKE_SIMPLE(Slider, ofParameter<float> &);

			// Add Widgets::EditableValue string
			OFXCVGUI_PANELS_WIDGETS_MAKE_SIMPLE(EditableValue<string>, ofParameter<string> &);

			// Add Widgets::EditableValue int
			OFXCVGUI_PANELS_WIDGETS_MAKE_SIMPLE(EditableValue<int>, ofParameter<int> &);

			// Add Widgets::Toggle
			OFXCVGUI_PANELS_WIDGETS_MAKE_SIMPLE(Toggle, ofParameter<bool> &);
		};
	}
}