#include QMK_KEYBOARD_H

#include "oneshot.h"
#include "print.h"


enum layer_names {
  _QWERTY,
  _SYM,
  _MOD,
  _NAV,
  _NUM,
  _ADJ
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
};

#define SPC_SFT SFT_T(KC_SPC)
#define TAB_NUM_NAV LT(_NUM_NAV, KC_TAB)
#define ESC_SYM LT(_SYM, KC_ESC)
#define LA_MOD MO(_MOD)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * +-----------------------------------------------.                    +-----------------------------------------------+
     * |       |   Q   |   W   |   E   |   R   |   T   |                    |   Y   |   U   |   I   |   O   |   P   |       |
     * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     * |       |   A   |   S   |   D   |   F   |   G   |                    |   H   |   J   |   K   |   L   |   '   |       |
     * |-------+-------+-------+-------+-------+-------|-------+    +-------|-------+-------+-------+-------+-------+-------|
     * |       |   Z   |   X   |   C   |   V   |   B   |       |    |       |   N   |   M   |   ,   |   .   |   ?   |       |
     * +-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------+
     *                         |       |  BSPC |  SPC  | tab/N |    | esc/S |   M   |  ent  |       |
     *                         +-------------------------------+    +-------------------------------+
     */
    [_QWERTY] = LAYOUT_6x6(
        KC_TAB , KC_Q    , KC_W    , KC_E     , KC_R    , KC_T     ,                          KC_Y  , KC_U     , KC_I     , KC_O    , KC_P      , KC_BSPC ,
        KC_ESC , KC_A    , KC_S    , KC_D     , KC_F    , KC_G     ,                          KC_H  , KC_J     , KC_K     , KC_L    , KC_QUOT   , KC_ENT  ,
        KC_NO  , KC_Z    , KC_X    , KC_C     , KC_V    , KC_B     ,                          KC_N  , KC_M     , KC_COMM  , KC_DOT  , KC_QUES   , KC_NO   ,
                          KC_NO   , MO(_NAV) , KC_SPC  , OS_SHFT  , OS_CTRL ,      OS_ALT , OS_CMD , MO(_NUM) , MO(_SYM) , KC_NO    
    ),
    /* MOD
     * +-----------------------------------------------.                    +-----------------------------------------------+
     * |       |       |       |  C-E  |  C-R  |  S-T  |                    |       |       |       |  S-O  |  S-P  |       |
     * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     * |       |  C-A  |  S-S  |  C-D  |  S-F  |  C-G  |                    |       |  cmd  |  ctrl |  alt  |  shft |       |
     * |-------+-------+-------+-------+-------+-------|-------+    +-------|-------+-------+-------+-------+-------+-------|
     * |       |  S-Z  |  S-X  |  S-C  |  S-V  |       |       |    |       |  S-N  |       |   S-, |       |       |       |
     * +-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------+
     *                         |       |       |       |       |    |       |       |       |       |
     *                         +-------------------------------+    +-------------------------------+
     */
    [_MOD] = LAYOUT_6x6(
      _______ , _______ , _______ , C(KC_E) , C(KC_R) , G(KC_T) ,                           _______ , _______ , _______    , G(KC_O) , G(KC_P) , _______ ,
      _______ , C(KC_A) , G(KC_S) , C(KC_D) , G(KC_F) , C(KC_G) ,                           _______ , OS_CMD  , OS_CTRL    , OS_ALT  , OS_SHFT , _______ ,
      _______ , G(KC_Z) , G(KC_X) , G(KC_C) , G(KC_V) , _______ ,                           G(KC_N) , _______ , G(KC_COMM) , _______ , _______ , _______ ,
                          _______ , _______ , _______ , _______  , _______ ,      _______ , _______ , _______ , _______    , _______   
    ),
    /*SYM
     * +-----------------------------------------------.                    +-----------------------------------------------+
     * |       |       |   *   |   +   |   -   |   /   |                    |   $   |   &   |   |   |   ^   |   ]   |       |
     * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     * |       |   )   |  (    |   [   |   {   |   @   |                    |   !   |   :   |   "   |   _   |   ;   |       |
     * |-------+-------+-------+-------+-------+-------|-------+    +-------|-------+-------+-------+-------+-------+-------|
     * |       |   \   |  `    |   #   |   =   |   ~   |       |    |       |       |   %   |   <   |   >   |   }   |       |
     * +-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------+
     *                         |       |       |       |       |    |       |       |       |       |
     *                         +-------------------------------+    +-------------------------------+
     */
    [_SYM] = LAYOUT_6x6(
      _______ , _______ , KC_ASTR , KC_PLUS , KC_MINS , KC_SLSH ,                           KC_DLR  , KC_AMPR , KC_PIPE , KC_CIRC , KC_RBRC , _______ ,
      _______ , KC_RPRN , KC_LPRN , KC_LBRC , KC_LCBR , KC_AT   ,                           KC_EXLM , KC_COLN , KC_DQT  , KC_UNDS , KC_SCLN , _______ ,
      _______ , KC_BSLS , KC_GRV  , KC_HASH , KC_EQL  , KC_TILD ,                           _______ , KC_PERC , KC_LT   , KC_GT   , KC_RCBR , _______ ,
                          _______ , _______ , _______ , _______  , _______ ,      _______ , _______ , _______ , _______ , _______   
    ),
    [_NAV] = LAYOUT_6x6(
      KC_ACL0 , _______ , KC_BTN1 , KC_MS_U , KC_BTN2 , KC_WH_U ,                           KC_HOME    , _______ , _______ , KC_END     , _______ , _______ ,
      KC_ACL1 , _______ , KC_MS_L , KC_MS_D , KC_MS_R , KC_WH_D ,                           KC_LEFT    , KC_DOWN , KC_UP   , KC_RGHT    , _______ , _______ ,
      KC_ACL2 , _______ , KC_WH_L , _______ , KC_WH_R , _______ ,                           A(KC_LEFT) , KC_PGDN , KC_PGUP , A(KC_RGHT) , _______ , _______ ,
                          _______ , _______ , _______ , _______ , _______ ,       _______ , _______ , _______ , _______ , _______    
    ),
    [_NUM] = LAYOUT_6x6(
      _______ , _______ , KC_8    , KC_7    , KC_6    , KC_5    ,                           _______    , KC_F1   , KC_F2   , KC_F3      , KC_F4   , _______ ,
      _______ , KC_4    , KC_3    , KC_2    , KC_1    , KC_0    ,                           KC_F5      , KC_F7   , KC_F8   , KC_F9      , KC_F10  , _______ ,
      _______ , _______ , _______ , _______ , _______ , KC_9    ,                           KC_F6      , KC_F11  , KC_F12  , _______    , _______ , _______ ,
                          _______ , _______ , _______ , _______ , _______ ,       _______ , _______ , _______ , _______ , _______    
    ),
    /* ADJ
     * +-----------------------------------------------.                    +-----------------------------------------------+
     * |       |  MR1  |  MRR1 | MRSTP | L/OSX | cpslk |                    |       | bridn | briup |       | PSCR  |       |
     * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
     * |       |  F1   |       |  prv  | pl/pau|  nxt  |                    |  mute | voldn | volup |       |  F12  |       |
     * |-------+-------+-------+-------+-------+-------|-------+    +-------|-------+-------+-------+-------+-------+-------|
     * |       |  F2   |   F3  |   F4  |   F5  |   F6  |       |    |       |   F7  |   F8  |  F9   |  F10  |  F11  |       |
     * +-------+-------+-------+-------+-------+-------+-------|    |-------+-------+-------+-------+-------+-------+-------+
     *                         |       | RESET |       |       |    |       |       |       |       |
     *                         +-------------------------------+    +-------------------------------+
     */
    [_ADJ] = LAYOUT_6x6(
      _______ , DM_REC1 , DM_PLY1 , DM_RSTP , _______ , KC_CLCK ,                           _______    , KC_BRID , KC_BRIU , _______    , KC_PSCR , _______ ,
      _______ , KC_F1   , _______ , KC_MRWD , KC_MPLY , KC_MFFD ,                           KC_MUTE    , KC_VOLD , KC_VOLU , _______    , KC_F12   , _______ ,
      _______ , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,                           KC_F7      , KC_F8   , KC_F9   , KC_F10     , KC_F11   , _______ ,
                          _______ , _______ , _______ , _______ , _______ ,       _______ , _______ , _______ , _______ , _______    
    )
};

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_MOD:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_MOD:
    case ESC_SYM:
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