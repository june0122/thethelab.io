.Java - VM(Virtual Machine) 기반 언어
=> 제임스 고슬링
=> 임베디드 목적

.kt

    compile
.java  =>   .class              => JVM
            (Byte Code,중간 언어)
jruby
jython
closure
scala
kotlin
groovy


Windows => JVM
Linux   => JVM   Hello.class <- Hello.java
Mac     => JVM          
          -> Hot Spot
    "Write Once, Run Anywhere"
       

Windows => .Net Runtime Hello.exe <- Hello.cs   C#
                                  <- Hello.cpp  C++
                                  <- Hello.vb   Visual Basic
Mono Opensource
 Mac    => .Net Runtime
 Linux  => .Net Runtime

-------------------------------
Prog1(Intel)
Prog1(ARM)
         
Prog(.c) -> Intel
         -> Arm  

x86/amd64 - ASM 명령 체계
  1.c -> a.intel.out
      -> a.arm.out

다른 CPU의 명령으로 번역하는 컴파일러
  => 크로스 컴파일러

ARM 명령 체계
  AP(CPU)
     Apple   - Ax
     Samsung - 엑시노스
     퀄컴     - 스냅 드래곤
     엔비디아  - 테그라

