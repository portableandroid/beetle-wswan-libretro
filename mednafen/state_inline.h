#ifndef _STATE_IN_HPP
#define _STATE_IN_HPP

INLINE bool SF_IS_BOOL(bool *) { return(1); }
INLINE bool SF_IS_BOOL(void *) { return(0); }

#define SFVARN(x, n) { &(x), SF_IS_BOOL(&(x)) ? 1 : (uint32_t)sizeof(x), MDFNSTATE_RLSB | (SF_IS_BOOL(&(x)) ? MDFNSTATE_BOOL : 0), n }
#define SFVAR(x) SFVARN((x), #x)

#define SFARRAYN(x, l, n) { (x), (uint32_t)(l), 0, n }
#define SFARRAY(x, l) SFARRAYN((x), (l), #x)

#define SFARRAY16N(x, l, n) { (x), (uint32_t)((l) * sizeof(uint16_t)), MDFNSTATE_RLSB16, n }
#define SFARRAY16(x, l) SFARRAY16N((x), (l), #x)

#define SFARRAY32N(x, l, n) { (x), (uint32_t)((l) * sizeof(uint32_t)), MDFNSTATE_RLSB32, n }
#define SFARRAY32(x, l) SFARRAY32N((x), (l), #x)

#define SFARRAY64N(x, l, n) { (x), (uint32_t)((l) * sizeof(uint64_t)), MDFNSTATE_RLSB64, n }
#define SFARRAY64(x, l) SFARRAY64N((x), (l), #x)

#define SFEND { 0, 0, 0, 0 }

#endif
