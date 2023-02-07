#include <setjmp.h>
#include <stdio.h>

jmp_buf env;

void f1(void);
void f2(void);

int main(void){
    if (setjmp(env)==0)
//        $rbp   : 0x007fffffffde70  →  0x0000000000000001
//    $rsi   : 0x0
//    $rdi   : 0x00555555558040  →  <env+0> add BYTE PTR [rax], al
//    $rip   : 0x007ffff7c421e6  →  <_setjmp+6> jmp 0x7ffff7c42110 <__sigsetjmp>
//        $r9    : 0x005555555592a0  →  "setjmp returned 0\n"

            printf("setjmp returned 0\n");
    else {
        printf("Program terminates; longjmp called\n");
        return 0;
    }
    f1();
    printf("Program terminates normally\n");
    return 0;
}

void f1(void) {
//    $rdi   : 0x0055555555605f  →  "f1 begins"
// $r9    : 0x005555555592a0  →  "f1 begins\nurned 0\n"
    printf("f1 begins\n");
    f2();
    printf("f1 returns\n");
}

void f2(void) {
//    ef➤  disas f2
//    Dump of assembler code for function f2:
//    0x0000555555555216 <+0>:     endbr64
//    0x000055555555521a <+4>:     push   rbp
//    0x000055555555521b <+5>:     mov    rbp,rsp
//    0x000055555555521e <+8>:     lea    rax,[rip+0xe4f]        # 0x555555556074
//    0x0000555555555225 <+15>:    mov    rdi,rax
//    0x0000555555555228 <+18>:    call   0x555555555070 <puts@plt>

    printf("f2 begins\n");

//    → 0x555555555228 <f2+18>          call   0x555555555070 <puts@plt>
//    ↳  0x555555555070 <puts@plt+0>     endbr64
//    0x555555555074 <puts@plt+4>     bnd    jmp QWORD PTR [rip+0x2f45]        # 0x555555557fc0 <puts@got.plt>
//                                                                                                    0x55555555507b <puts@plt+11>    nop    DWORD PTR [rax+rax*1+0x0]
//    0x555555555080 <_setjmp@plt+0>  endbr64
//    0x555555555084 <_setjmp@plt+4>  bnd    jmp QWORD PTR [rip+0x2f3d]        # 0x555555557fc8 <_setjmp@got.plt>
//                                                                                                       0x55555555508b <_setjmp@plt+11> nop    DWORD PTR [rax+rax*1+0x0]
//    ────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────── arguments (guessed) ────
//    puts@plt (
//            $rdi = 0x00555555556074 → "f2 begins",
/*
 * C Calling Conventions amd64 Linux
 * Order is longjmp(RDI, RSI, RDX, RCX, R8, R9)
 * #0] Id 1, Name: "a.out", stopped 0x7ffff7c421f0 in __libc_siglongjmp (), reason: SINGLE STEP
──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────── trace ────
[#0] 0x7ffff7c421f0 → __libc_siglongjmp(env=0x555555558040 <env>, val=0x1)
[#1] 0x555555555241 → f2()
[#2] 0x555555555204 → f1()
[#3] 0x5555555551bc → main()
─────────────────────────────────
 env is a void pointer in RDI and the length of the jump is 0x1 in RSI
 * */
    longjmp(env, 1);
    printf("f2 returns\n");
}
