#pragma once

// NOTE: This may break keyboard functionality in the BIOS (or other
//       environments that only support the 'boot protocol' which allows only
//       6-key rollover). NK_TOGG can turn NKRO off, and that choice persists.
#define NKRO_DEFAULT_ON true

// The default of 200 ms is a bit too slow.
#define TAPPING_TERM 125

// VIA defaults to 4 layers, but this keymap has 5.
#define DYNAMIC_KEYMAP_LAYER_COUNT 5
