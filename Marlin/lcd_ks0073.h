#ifndef lcd_ks0073_h
#define lcd_ks0073_h

#include <inttypes.h>
#include "Print.h"


class LcdKS0073: public Print {
public:
  LcdKS0073();
  
  void begin(uint8_t cols, uint8_t rows);

  void clear();
  void home();

  void noDisplay();
  void display();
  void noBlink();
  void blink();
  void noCursor();
  void cursor();
  void scrollDisplayLeft();
  void scrollDisplayRight();
  void leftToRight();
  void rightToLeft();
  void autoscroll();
  void noAutoscroll();

  void createChar(uint8_t, uint8_t[]);
  void setCursor(uint8_t, uint8_t); 
  size_t write(uint8_t);
  void command(uint8_t);
  
  using Print::write;

private:
  void lcd_e_toggle();
  uint8_t lcd_check_connection(uint8_t ms);
  void lcd_command(uint8_t cmd);
  void lcd_clrscr(void);
  uint8_t lcd_waitbusy(void);
  void lcd_write(uint8_t data,uint8_t rs);
  uint8_t lcd_read(uint8_t rs) ;

};

#endif
