#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "print.h"

enum layer_names {
  _QWERTY,
  _NAV,
  _NUM,
  _FUNC,
  _SYM,
  _ADJ,
  _MACRO
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
};

#define SPC_SFT   SFT_T(KC_SPC)
#define NAV       MO(_NAV)
#define BSPC_NUM  LT(_NUM, KC_BSPC)
#define TAB_SYM   LT(_SYM, KC_TAB)
#define ESC_FUNC  LT(_FUNC, KC_ESC)
#define ENT_MACRO LT(_MACRO, KC_ENT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * +---------------------------------------.                    +---------------------------------------+
     * |   Q   |   W   |   E   |   R   |   T   |                    |   Y   |   U   |   I   |   O   |   P   |
     * +-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+
     * |   A   |   S   |   D   |   F   |   G   |                    |   H   |   J   |   K   |   L   |   .   |
     * +-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+
     * |   Z   |   X   |   C   |   V   |   B   |                    |   N   |   M   |  cmd  |  ctrl |  alt  |
     * +-------+-------+-------+-------+-------+-------+    +-------+-------+-------+-------+-------+-------+
     *                         |  SPC/ | NAV   | ESC   |    | ENT   | TAB   | BSPC  |
     *                         |  SHFT |       | FUNC  |    | MACRO | SYM   | NUM   |
     *                         +-----------------------+    +------------------------
     */
    [_QWERTY] = LAYOUT_6x6(
        KC_Q    , KC_W    , KC_E    , KC_R    , KC_T  ,                             KC_Y    , KC_U     , KC_I    , KC_O    , KC_P   ,
        KC_A    , KC_S    , KC_D    , KC_F    , KC_G  ,                             KC_H    , KC_J     , KC_K    , KC_L    , KC_DOT ,
        KC_Z    , KC_X    , KC_C    , KC_V    , KC_B  ,                             KC_N    , KC_M     , OS_CMD  , OS_CTRL , OS_ALT ,
                                      SPC_SFT , NAV   , ESC_FUNC ,      ENT_MACRO , TAB_SYM , BSPC_NUM     
    ),
    [_FUNC] = LAYOUT_6x6(
      KC_F1  , KC_F2  , KC_F3   , KC_F4   , KC_VOLU ,                           KC_BRIU , DM_REC1 , DM_PLY1 , DM_RSTP , _______ ,
      KC_F5  , KC_F6  , KC_F7   , KC_F8   , KC_VOLD ,                           KC_BRID , _______ , _______ , _______ , _______ ,
      KC_F9  , KC_F10 , KC_F11  , KC_F12  , KC_MUTE ,                           _______ , _______ , _______ , _______ , _______ ,
                        KC_MRWD , KC_MPLY , KC_MFFD ,                           _______ , _______ , _______  

    ),
    [_NAV] = LAYOUT_6x6(
      _______ , _______ , _______ , _______ , _______ ,                           KC_HOME    , G(KC_DOWN) , G(KC_UP), KC_END     , _______ ,
      _______ , _______  , _______ , _______  , _______ ,                         KC_LEFT    , KC_DOWN    , KC_UP   , KC_RGHT    , _______ ,
      _______ , _______ , _______ , _______ , _______ ,                           A(KC_LEFT) , KC_PGDN    , KC_PGUP , A(KC_RGHT) , _______ ,
                                    _______ , _______ , _______ ,       _______ , _______    , _______    
    ),
    [_NUM] = LAYOUT_6x6(
      _______ , KC_8    , KC_7    , KC_6    , KC_5    ,                           _______ , _______ , _______ , _______ , _______,
      KC_4    , KC_3    , KC_2    , KC_1    , KC_0    ,                           _______ , _______  , _______ , _______  , _______,
      _______ , _______ , _______ , _______ , KC_9    ,                           _______ , _______ , _______ , _______ , _______,
                                    _______ , _______ , _______ ,       _______ , _______ , _______    
    ),
    /*SYM
     * +---------------------------------------.                    +---------------------------------------+
     * |   ^   |   *   |   +   |   _   |   /   |                    |   &   |   =   |   %   |   #   |   `   |
     * |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
     * |   ~   |   (   |   [   |   {   |   @   |                    |   !   |   "   |   :   |   _   |   ;   |
     * |-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------|
     * |       |   )   |   ]   |   }   |   $   |                    |   |   |   '   |   <   |   >   |   \   |
     * +-------+-------+-------+-------+-------+-------+    +-------+-------+-------+-------+-------+-------+
     *                         |   .   |   ?   |   ,   |    |       |       |       |
     *                         +-----------------------+    +-----------------------+
     */
    [_SYM] = LAYOUT_6x6(
      KC_CIRC , KC_ASTR , KC_PLUS , KC_MINS , KC_SLSH ,                           KC_AMPR , KC_EQL  , KC_PERC , KC_HASH , KC_GRV ,
      KC_TILD , KC_LPRN , KC_LBRC , KC_LCBR , KC_AT   ,                           KC_EXLM , KC_DQT  , KC_COLN , KC_UNDS , KC_SCLN,
      _______ , KC_RPRN , KC_RBRC , KC_RCBR , KC_DLR  ,                           KC_PIPE , KC_QUOT , KC_LT   , KC_GT   , KC_BSLS,
                                     KC_DOT , KC_QUES , KC_COMM ,       _______ , _______ , _______   
    ),
    [_MACRO] = LAYOUT_6x6(
      _______ , _______ , _______ , _______ , _______ ,                           _______ , _______ , _______ , _______ , _______ ,
      _______ , _______ , _______ , _______ , _______ ,                           _______ , _______ , _______ , _______ , _______ ,
      _______ , _______ , _______ , _______ , _______ ,                           _______ , _______ , _______ , _______ , _______ ,
                                    _______ , _______ , _______ ,       _______ , _______ , _______    
    ),
    [_ADJ] = LAYOUT_6x6(
      _______ , _______ , _______ , _______ , _______ ,                           _______ , _______ , _______ , _______ , _______ ,
      _______ , _______ , _______ , _______ , _______ ,                           _______ , _______ , _______ , _______ , _______ ,
      _______ , _______ , _______ , _______ , _______ ,                           _______ , _______ , _______ , _______ , _______ ,
                                    _______ , _______ , _______ ,       _______ , _______ , _______    
    )
};

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case KC_DOT:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case NAV:
    case ESC_FUNC:
    case TAB_SYM:
    case BSPC_NUM:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
      // If console is enabled, it will print the matrix position and status of each key pressed
      
    #ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    #endif 
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return true;
}



layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _ADJ);
}