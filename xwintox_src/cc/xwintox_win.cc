#include <stdio.h>

#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_RGB_Image.H>
#include <FL/fl_draw.H>



#include "xwintox_win.h"
#include "svgs.h"
#include "nanosvg/nsvgwrap.h"

StatusBox::StatusBox(int X, int Y, int W, int H, int S) : Fl_Box (X, Y, W, H)
{
	scale =S;
	box(FL_FLAT_BOX);
	color(fl_rgb_color(65, 65, 65));
}

void StatusBox::draw()
{
	Fl_Box::draw();
	fl_color(2);
	fl_pie(this->x() + (5 * scale), this->y() + (15 * scale), 10 * scale,
			10 * scale, 0, 360);
}

SVGBox::SVGBox(int X, int Y, int W, int H, int S) : Fl_Box (X, Y, W, H)
{
	img_r =svgrast(default_av, W, H, S);
	img =new Fl_RGB_Image(img_r, W, H, 4);
	image(img);
}

Sidebar_Top_Area::Sidebar_Top_Area(int S) : Fl_Group (0, 0, 224 * S, 60 * S)
{
	scale =S;

	box(FL_FLAT_BOX);
	color(fl_rgb_color(28, 28, 28));

	statusbox =new StatusBox(192 * S, 10 * S, 20 * S, 40 * S, S);
	avbox =new SVGBox(10 * S, 10 * S, 40 * S , 40 * S, S);
	name =new Fl_Input(62 * S, 18 * S, 128 *S, 10 * S); 
	status =new Fl_Input(62 * S, 30 * S, 128 *S, 10 * S); 
	name->textsize(12 * S);
	status->textsize(10 * S);
	name->box(FL_FLAT_BOX); name->color(fl_rgb_color(28, 28, 28));
	status->box(FL_FLAT_BOX); status->color(fl_rgb_color(28, 28, 28));
	name->textcolor(255);
	status->textcolor(54);
	name->value("XwinTox User"); status->value("Toxing on XwinTox");
}

Sidebar::Sidebar(int S) : Fl_Group (0, 0, 224 * S, 480)
{
	scale =S;

	box(FL_FLAT_BOX);
	color(fl_rgb_color(65, 65, 65));
	top_area =new Sidebar_Top_Area(S);
}

void Sidebar::resize(int X, int Y, int W, int H)
{
	Fl_Group::resize(X, Y, W, H);
	top_area->resize(0, 0, 224 * scale, 60 * scale);
} 

XWContents::XWContents(int S) : Fl_Group (224 * S, 0, 416, 480)
{
	resizable(0);
	box(FL_FLAT_BOX);
	color(4);
	show();
}


XwinTox::XwinTox(int w, int h, const char* c, int S) : Fl_Double_Window(w, h, c) 
{
	scale =S;

	box(FL_FLAT_BOX);
	color(255);

	sidebar =new Sidebar(S);
	contents =new XWContents(S);

	resizable(contents);
}

void XwinTox::resize (int X, int Y, int W, int H)
{
	Fl_Double_Window::resize (X, Y, W, H);
	contents->resize(224 * scale, 0, W - (224 * scale), H);
}
