section .data
  msg db "Hello World!", 0xA  
  len equ $ -msg

  msg2 db "Welcome to the SleiwBank", 0xA
  len2 equ $ -msg2 
 
section .text 
  global_start

_start:
  mov rax, 1
  mov rdi, 1
  mov rsi, msg
  mov rdx, len
  syscall

  mov rax, 1
  mov rdi, 2  

  mov rax, 60
  xor rdi, rdi
  syscall
