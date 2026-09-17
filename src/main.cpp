#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/checkbox.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <random>
#include <string>
std::string generate_string(bool specs, bool upper, bool lower, bool nums,
                            int len);
int random_int(int min, int max);
const std::string strspec = "~`!@#$%^&*()-+/|\"?{}][;:<>\\";
const std::string strcaps = "QWERTYUIOPASDFGHJKLZXCVBNM";
const std::string strnocaps = "qwertyuiopasdfghjklzxcvbnm";
const std::string strnumbers = "0123456789";

int main() {
  const int checkbox_y = 270;
  const int checkbox_basex = 150;
  nana::form window{nana::rectangle(0, 0, 1280, 720)};
  window.caption("Password generator");
  nana::button generate{window, nana::rectangle(5, 5, 200, 40)};
  nana::checkbox spec_symbols{
      window, nana::rectangle(checkbox_basex, checkbox_y, 200, 40)};
  nana::checkbox caps{
      window, nana::rectangle(checkbox_basex + 200, checkbox_y, 200, 40)};
  nana::checkbox nocaps{
      window, nana::rectangle(checkbox_basex + 400, checkbox_y, 200, 40)};
  nana::checkbox numbers{
      window, nana::rectangle(checkbox_basex + 600, checkbox_y, 200, 40)};
  nana::textbox tbox{window, nana::rectangle(150, 200, 500, 40)};
  nana::textbox inputbox{window, nana::rectangle(250, 5, 200, 20)};

  spec_symbols.caption("special_symbols");
  caps.caption("Uppercase");
  nocaps.caption("lowercase");
  numbers.caption("numbers");
  generate.caption("generate");
  inputbox.caption("input a password length");
  generate.events().click(

      [&spec_symbols, &caps, &nocaps, &numbers, &tbox, &inputbox]() -> void {
        bool error = false;
        for (auto i : inputbox.text())
          if ((int)i > 57 || (int)i < 48) {
            tbox.caption("len contains NaN character");
            error = true;
          }
        if (error) {
          return;
        }
        int len = 0;
        for (auto i : inputbox.text()) {
          len *= 10;          // for 3: 0 10 20
          len += (int)i - 48; // 1 12 123
        }
        std::string s =
            generate_string(spec_symbols.checked(), caps.checked(),
                            nocaps.checked(), numbers.checked(), len);
        tbox.caption(s);
      });

  window.show();
  nana::exec();
}

std::string generate_string(bool specs, bool upper, bool lower, bool nums,
                            int len) {
  std::string s = "";
  if (specs)
    s += strspec;
  if (upper)
    s += strcaps;
  if (lower)
    s += strnocaps;
  if (nums)
    s += strnumbers;
  if (s == "")
    return "";
  std::string for_return = "";
  for (int i = 0; i < len; ++i) {
    int index = random_int(0, s.length() - 1);
    for_return += s[index];
  }
  return for_return;
}
int random_int(int min, int max) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(min, max);
  return dist(gen);
}
