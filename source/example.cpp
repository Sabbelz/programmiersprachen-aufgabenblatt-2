#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "color.hpp"
#include <vector>


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};


  Vec2 min{200.0f, 600.0f};
  Vec2 max{400.0f, 700.0f};
  Vec2 ctr{600.0f, 600.0f};
  Vec2 ctr_2{300.0f, 300.0f};
  Vec2 second{0.0f, -350.0f};
  Vec2 minute{0.0f, -275.0f};
  Vec2 hour{0.0f, -200.0f};

  Color col{0.0f, 0.9f, 0.5f};
  Color clr{153.0f/255.0f,50.0f/255.0f,204.0f/255.0f};

  Rectangle rec{};
  Rectangle rec_2{min, max, clr};

  Circle cir{};
  Circle cir_2{150.0f, ctr, clr};
  Circle cir_3{50.0f, ctr_2, clr};

  std::vector<Rectangle>rectangles;
  std::vector<Circle>circles;

  rectangles.push_back(rec);
  rectangles.push_back(rec_2);

  circles.push_back(cir);
  circles.push_back(cir_2);
  circles.push_back(cir_3);

  while (!win.should_close()) {

    float time = win.get_time();
    float seconds = fmod(time,60);
    float minutes = fmod((time/60),60);
    float hours = fmod((time/3600),12);
    float sec_degree = seconds * ((M_PI/180)*6);
    float min_degree = minutes * ((M_PI/180)*6);
    float h_degree = hours * ((M_PI/180)*30);
    Mat2 sec_rot = make_rotation_mat2(sec_degree);
    Mat2 min_rot = make_rotation_mat2(min_degree);
    Mat2 h_rot = make_rotation_mat2(h_degree);

    /*float startX, float startY,
                float endX, float endY,
                float r, float g, float b,
                float thickness = 1.0*/
    Vec2 sec_now = sec_rot * second;
    Vec2 min_now = min_rot * minute;
    Vec2 h_now = h_rot * hour;

    win.draw_line(400.0f,400.0f, sec_now.x+400.0f, sec_now.y+400.0f, 1.0f,0.0f,0.0f);
    win.draw_line(400.0f,400.0f, min_now.x+400.0f, min_now.y+400.0f, 0.0f,1.0f,0.0f);
    win.draw_line(400.0f,400.0f, h_now.x+400.0f, h_now.y+400.0f, 0.0f,0.0f,1.0f);



    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    for(Rectangle const& r: rectangles){
      if(r.is_inside({(float) std::get<0>(win.mouse_position()), (float) std::get<1>(win.mouse_position())})){ //cast auf float get<x> pos vom wert
        r.draw(win, col);
      }
      else{
        r.draw(win);
      }
    }
    for(Circle const& c: circles){
      if(c.is_inside({(float) std::get<0>(win.mouse_position()), (float) std::get<1>(win.mouse_position())})){
        c.draw(win, col);
      }
      else{
        c.draw(win);
      }
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);

    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);

    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto mouse_position = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    1.0,0.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
    }

    win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

    win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";
    
    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);

    win.update();
  }

  return 0;
}
