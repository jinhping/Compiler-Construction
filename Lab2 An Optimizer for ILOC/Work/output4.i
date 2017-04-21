read => r1
loadI 0 => r0
subI r1, 1 => r12
cmp_LE r0, r12 => r13
cbr r13 -> L0, L1
L0: nop
loadI 0 => r14
subI r0, 0 => r15
add r14, r15 => r14
lshiftI r14, 2 => r14
loadI 20 => r16
add r16, r14 => r16
read => r17
store r17 => r16
addI r0, 1 => r0
cmp_LE r0, r12 => r18
cbr r18 -> L0, L1
L1: nop
loadI 0 => r20
subI r20, 1 => r19
i2i r19 => r11
loadI 0 => r21
loadI 0 => r22
add r21, r22 => r21
lshiftI r21, 2 => r21
loadI 40024 => r23
add r23, r21 => r23
store r11 => r23
loadI 0 => r24
loadI 1 => r25
add r24, r25 => r24
lshiftI r24, 2 => r24
loadI 40024 => r26
add r26, r24 => r26
store r11 => r26
loadI 0 => r27
loadI 2 => r28
add r27, r28 => r27
lshiftI r27, 2 => r27
loadI 40024 => r29
add r29, r27 => r29
loadI 0 => r30
store r30 => r29
loadI 0 => r31
loadI 3 => r32
add r31, r32 => r31
lshiftI r31, 2 => r31
loadI 40024 => r33
add r33, r31 => r33
subI r1, 1 => r34
store r34 => r33
loadI 4 => r9
loadI 0 => r10
loadI 1 => r35
cmp_GT r9, r35 => r36
cbr r36 -> L2, L3
L2: nop
subI r9, 2 => r37
loadI 0 => r38
subI r37, 0 => r39
add r38, r39 => r38
lshiftI r38, 2 => r38
loadI 40024 => r40
add r40, r38 => r40
load r40 => r41
i2i r41 => r4
subI r9, 1 => r42
loadI 0 => r43
subI r42, 0 => r44
add r43, r44 => r43
lshiftI r43, 2 => r43
loadI 40024 => r45
add r45, r43 => r45
load r45 => r46
i2i r46 => r5
i2i r37 => r47
i2i r47 => r9
addI r10, 1 => r48
i2i r48 => r10
loadI 1000 => r49
cmp_GT r10, r49 => r50
cbr r50 -> L4, L5
L4: nop
i2i r11 => r9
L5: nop
cmp_LT r4, r5 => r51
cbr r51 -> L7, L8
L7: nop
loadI 0 => r52
subI r4, 0 => r53
add r52, r53 => r52
lshiftI r52, 2 => r52
loadI 20 => r54
add r54, r52 => r54
load r54 => r55
loadI 0 => r56
subI r5, 0 => r57
add r56, r57 => r56
lshiftI r56, 2 => r56
loadI 20 => r58
add r58, r56 => r58
load r58 => r59
add r55, r59 => r60
add r4, r5 => r61
divI r61, 2 => r62
loadI 0 => r63
subI r62, 0 => r64
add r63, r64 => r63
lshiftI r63, 2 => r63
loadI 20 => r65
add r65, r63 => r65
load r65 => r66
add r60, r66 => r67
divI r67, 3 => r68
i2i r68 => r6
i2i r4 => r2
i2i r5 => r3
sub r3, r2 => r69
loadI 1 => r70
cmp_EQ r69, r70 => r71
cbr r71 -> L10, L11
L10: nop
loadI 0 => r72
subI r2, 0 => r73
add r72, r73 => r72
lshiftI r72, 2 => r72
loadI 20 => r74
add r74, r72 => r74
load r74 => r75
loadI 0 => r76
subI r3, 0 => r77
add r76, r77 => r76
lshiftI r76, 2 => r76
loadI 20 => r78
add r78, r76 => r78
load r78 => r79
cmp_GT r75, r79 => r80
cbr r80 -> L13, L14
L13: nop
loadI 0 => r81
subI r2, 0 => r82
add r81, r82 => r81
lshiftI r81, 2 => r81
loadI 20 => r83
add r83, r81 => r83
load r83 => r84
i2i r84 => r8
loadI 0 => r85
i2i r82 => r86
add r85, r86 => r85
lshiftI r85, 2 => r85
loadI 20 => r87
add r87, r85 => r87
loadI 0 => r88
subI r3, 0 => r89
add r88, r89 => r88
lshiftI r88, 2 => r88
loadI 20 => r90
add r90, r88 => r90
load r90 => r91
store r91 => r87
loadI 0 => r92
i2i r89 => r93
add r92, r93 => r92
lshiftI r92, 2 => r92
loadI 20 => r94
add r94, r92 => r94
store r8 => r94
L14: nop
br -> L12
L11: nop
sub r3, r2 => r95
loadI 1 => r96
cmp_GT r95, r96 => r97
cbr r97 -> L16, L17
L16: nop
loadI 1 => r7
cbr r7 -> L19, L20
L19: nop
loadI 0 => r98
subI r2, 0 => r99
add r98, r99 => r98
lshiftI r98, 2 => r98
loadI 20 => r100
add r100, r98 => r100
load r100 => r101
cmp_LT r101, r6 => r102
cbr r102 -> L21, L22
L21: nop
addI r2, 1 => r103
i2i r103 => r2
loadI 0 => r98
subI r2, 0 => r99
add r98, r99 => r98
lshiftI r98, 2 => r98
loadI 20 => r100
add r100, r98 => r100
load r100 => r101
cmp_LT r101, r6 => r102
cbr r102 -> L21, L22
L22: nop
loadI 0 => r104
subI r3, 0 => r105
add r104, r105 => r104
lshiftI r104, 2 => r104
loadI 20 => r106
add r106, r104 => r106
load r106 => r107
cmp_GT r107, r6 => r108
cbr r108 -> L23, L24
L23: nop
subI r3, 1 => r109
i2i r109 => r3
loadI 0 => r104
subI r3, 0 => r105
add r104, r105 => r104
lshiftI r104, 2 => r104
loadI 20 => r106
add r106, r104 => r106
load r106 => r107
cmp_GT r107, r6 => r108
cbr r108 -> L23, L24
L24: nop
cmp_LT r2, r3 => r110
cbr r110 -> L25, L26
L25: nop
loadI 0 => r111
subI r2, 0 => r112
add r111, r112 => r111
lshiftI r111, 2 => r111
loadI 20 => r113
add r113, r111 => r113
load r113 => r114
i2i r114 => r8
loadI 0 => r115
i2i r112 => r116
add r115, r116 => r115
lshiftI r115, 2 => r115
loadI 20 => r117
add r117, r115 => r117
loadI 0 => r118
subI r3, 0 => r119
add r118, r119 => r118
lshiftI r118, 2 => r118
loadI 20 => r120
add r120, r118 => r120
load r120 => r121
store r121 => r117
loadI 0 => r122
i2i r119 => r123
add r122, r123 => r122
lshiftI r122, 2 => r122
loadI 20 => r124
add r124, r122 => r124
store r8 => r124
br -> L27
L26: nop
loadI 0 => r7
br -> L27
L27: nop
cbr r7 -> L19, L20
L20: nop
loadI 0 => r125
subI r9, 0 => r126
add r125, r126 => r125
lshiftI r125, 2 => r125
loadI 40024 => r127
add r127, r125 => r127
store r4 => r127
addI r9, 1 => r128
loadI 0 => r129
subI r128, 0 => r130
add r129, r130 => r129
lshiftI r129, 2 => r129
loadI 40024 => r131
add r131, r129 => r131
subI r2, 1 => r132
store r132 => r131
addI r9, 2 => r133
loadI 0 => r134
subI r133, 0 => r135
add r134, r135 => r134
lshiftI r134, 2 => r134
loadI 40024 => r136
add r136, r134 => r136
store r3 => r136
addI r9, 3 => r137
loadI 0 => r138
subI r137, 0 => r139
add r138, r139 => r138
lshiftI r138, 2 => r138
loadI 40024 => r140
add r140, r138 => r140
store r5 => r140
addI r9, 4 => r141
i2i r141 => r9
L17: nop
br -> L12
L12: nop
L8: nop
loadI 1 => r35
cmp_GT r9, r35 => r36
cbr r36 -> L2, L3
L3: nop
loadI 0 => r0
subI r1, 1 => r142
cmp_LE r0, r142 => r143
cbr r143 -> L28, L29
L28: nop
loadI 0 => r144
subI r0, 0 => r145
add r144, r145 => r144
lshiftI r144, 2 => r144
loadI 20 => r146
add r146, r144 => r146
load r146 => r147
write r147	
addI r0, 1 => r0
cmp_LE r0, r142 => r148
cbr r148 -> L28, L29
L29: nop
halt
