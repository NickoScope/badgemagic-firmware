#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "CH58x_common.h"

enum keys {
	KEY1 = 0,
	KEY2,
	KEY3,
	KEY4,
	KEY_INDEX,
};

#define KEY2_PIN (GPIO_Pin_22) // PB
#define KEY1_PIN (GPIO_Pin_1) // PA

#define isPressed(key) 		((key) ? \
				!GPIOB_ReadPortPin(KEY2_PIN) : \
				GPIOA_ReadPortPin(KEY1_PIN))

void btn_onOnePress(int key, void (*handler)(void));
void btn_onLongPress(int key, void (*handler)(void));

typedef void (*btn_handler_t)(void);

/* Debounced edges, independent of onOnePress/onLongPress: onPress fires on
 * the first scan a key reads pressed, onRelease on the first scan it reads
 * released, whatever the hold time. Both default to NULL, so nothing
 * changes for code that does not use them. The getters let a mode save
 * the current onOnePress/onLongPress bindings and put them back later. */
void btn_onPress(int key, btn_handler_t handler);
void btn_onRelease(int key, btn_handler_t handler);
btn_handler_t btn_getOnePress(int key);
btn_handler_t btn_getLongPress(int key);
void btn_init();
void btn_init_task(void);
void btn_tick(void);

#endif /* __BUTTON_H__ */
