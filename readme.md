# btgrant-76's userspace

## Core Keymap 

My keymap is heavily inspired by [Miryoku](https://github.com/manna-harbour/miryoku/). The core keymap is managed in [`btgrant-76.h`](./btgrant-76.h). Each layer is divided into left and right halves; the halves are composed of:

* a set of three, 5u rows
* a set of 3u thumb clusters

These rows and thumb clusters are then composed into an individual keyboard's `keymap.c`. Additional keycodes supplement the core keymap where they are required to satisfy the board's defined number of keys.

Big thanks to [waffle87](https://github.com/waffle87) for inspiration and assistance to get this centrally-managed keymap working.

### Layers

Conventions:

* Keys that leverage [Tap-Hold](https://docs.qmk.fm/#/tap_hold) are expressed as `tap/hold`
* `---` represents `KC_NO`/NOOP

#### Base (`BASE`)

```text
╭────────┬────────┬────────┬────────┬────────╮  ╭────────┬────────┬────────┬────────┬────────╮ 
│  Q     │  W     │  E     │  R     │  T     │  │  Y     │  U     │  I     │  O     │  P     │ 
├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤ 
│  A/Ctl │  S/Alt │  D/Cmd │  F/Sft │  G     │  │  H     │  J/Sft │  K/Cmd │  L/Alt │ ; :/Ctl│ 
├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤ 
│ Z/Hypr │  X     │  C     │  V     │  B/Meh │  │  N/Meh │  M     │  , <   │  . >   │/ ?/Hypr│ 
╰────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┴────────╯ 
                  │ Tab/FUN│ BS/NUM │ Esc/SYM│  │ Ent/MSE│ Spc/NAV│ Del/MED│ 
                  ╰────────┴────────┴────────╯  ╰────────┴────────┴────────╯ 
```

#### Number (`NUM`)

```text
╭────────┬────────┬────────┬────────┬────────╮  ╭────────┬────────┬────────┬────────┬────────╮ 
│  Undo  │  Cut   │  Copy  │  Paste │  Redo  │  │  [ {   │  7     │  8     │  9     │  ] }   │ 
├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤ 
│  Ctl   │  S/Alt │  Cmd   │  Shift │Capwd TG│  │  = +   │  4     │  5     │  6     │  ' "   │ 
├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤ 
│ leader │  ---   │ leader │ Space  │Backspc │  │  \ |   │  1     │  2     │  3     │  ` ~   │ 
╰────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┴────────╯ 
                  │  Del   │ (hold) │  BS    │  │  - _   │  0     │  .     │ 
                  ╰────────┴────────┴────────╯  ╰────────┴────────┴────────╯ 
```

#### Symbol (`SYM`)

```text
╭────────┬────────┬────────┬────────┬────────╮  ╭────────┬────────┬────────┬────────┬────────╮ 
│  ---   │  ---   │  ---   │  ---   │  ---   │  │  {     │  &     │  *     │  )     │  }     │ 
├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤ 
│ Med <==│ Vol Up │ Vol Dn │ Med==> │RGB Spd+│  │  +     │  $     │  %     │  ^     │  "     │ 
├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤ 
│ RGB tog│RGB mod+│RGB hue+│RGB sat+│RGB brt+│  │  |     │  !     │  @     │  #     │  ~     │ 
╰────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┴────────╯ 
                  │  Mute  │Ply/Paus│  Stop  │  │  _     │  (     │  )     │ 
                  ╰────────┴────────┴────────╯  ╰────────┴────────┴────────╯ 
```

#### Navigation (`NAV`)

```text
╭────────┬────────┬────────┬────────┬────────╮  ╭────────┬────────┬────────┬────────┬────────╮ 
│ Tab Lft│  Back  │ Forward│Tab Rght│  ../   │  │  Redo  │  Paste │  Copy  │  Cut   │  Undo  │ 
├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤ 
│  Ctl   │  Alt   │  Cmd   │  Shft  │  ---   │  │  Left  │  Down  │  Up    │  Right │  Caps  │ 
├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤ 
│  ---   │  ---   │  ---   │  ---   │  ---   │  │  Home  │  PgDn  │  PgUp  │  End   │ Insert │ 
╰────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┴────────╯ 
                  │ Del/Cmd│  Bs    │  Ent   │  │  ---   │ (hold) │  ---   │ 
                  ╰────────┴────────┴────────╯  ╰────────┴────────┴────────╯ 
```

#### Function (`FUN`)

```text
╭────────┬────────┬────────┬────────┬────────╮  ╭────────┬────────┬────────┬────────┬────────╮ 
│ Log Out│  ---   │Scrn2Clp│ Scrn2Fl│  ---   │  │  ---   │  F7    │  F8    │  F9    │  F12   │ 
├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤ 
│  Ctl   │  Alt   │  Cmd   │  Shft  │  ---   │  │  ---   │  F4    │  F5    │  F6    │  F11   │ 
├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤ 
│  ---   │  ---   │  ---   │  ---   │  ---   │  │  ---   │  F1    │  F2    │  F3    │  F10   │ 
╰────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┴────────╯ 
                  │ (hold) │  Space │  Tab   │  │  ---   │  ADD   │  ---   │ 
                  ╰────────┴────────┴────────╯  ╰────────┴────────┴────────╯ 
```

#### Mouse Keys (`MSE`)

```text
╭────────┬────────┬────────┬────────┬────────╮  ╭────────┬────────┬────────┬────────┬────────╮
│  Undo  │  Cut   │  Copy  │  Paste │  Redo  │  │  ---   │MseSpd 0│MseSpd 1│MseSpd 2│  ---   │
├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
│ Mouse L│ Mouse U│ Mouse D│ Mouse U│  ---   │  │  ---   │  Shift │  Cmd   │  Alt   │  Ctrl  │
├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
│ Wheel L│ Wheel D│ Wheel U│ Wheel R│  ---   │  │  ---   │  ---   │  ---   │  ---   │  ---   │
╰────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┴────────╯
                  │Button 3│Button 1│Button 2│  │ (hold) │  ---   │  ---   │ 
                  ╰────────┴────────┴────────╯  ╰────────┴────────┴────────╯ 
```

#### Additional Features (`ADD`)

```text
╭────────┬────────┬────────┬────────┬────────╮  ╭────────┬────────┬────────┬────────┬────────╮
│ Bootldr│  ---   │  ---   │  ---   │  ---   │  │  Redo  │  Paste │  Copy  │  Cut   │  Undo  │
├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
│  ---   │DynTpRpt│ DynTpDn│ DynTpUp│  ---   │  │  ---   │  ---   │  ---   │  ---   │  ---   │
├────────┼────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
│  ---   │ ASftRpt│ ASft Dn│ ASft Up│  ---   │  │  ---   │  ---   │  ---   │  ---   │  ---   │
╰────────┴────────┼────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┴────────╯
                  │  ---   │  ---   │  ---   │  │  ---   │ (hold) │  ---   │
                  ╰────────┴────────┴────────╯  ╰────────┴────────┴────────╯
```