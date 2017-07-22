In file included from ./src/playstate.hpp:4:0,
                 from ./src/app.cpp:9:
./src/map.hpp:43:1: error: version control conflict marker in file
 <<<<<<< HEAD
 ^~~~~~~
./src/map.hpp: In member function ‘Physics& Map::physics()’:
./src/map.hpp:32:30: error: ‘ThePhysics’ was not declared in this scope
  Physics &physics() { return ThePhysics; }
                              ^~~~~~~~~~
./src/map.hpp: In member function ‘PlayerController& Map::player1()’:
./src/map.hpp:34:42: error: ‘Player1Controller’ was not declared in this scope
     PlayerController &player1() { return Player1Controller; }
                                          ^~~~~~~~~~~~~~~~~
./src/map.hpp: In member function ‘PlayerController& Map::player2()’:
./src/map.hpp:35:42: error: ‘Player2Controller’ was not declared in this scope
     PlayerController &player2() { return Player2Controller; }
                                          ^~~~~~~~~~~~~~~~~
./src/map.hpp: At global scope:
./src/map.hpp:45:1: error: version control conflict marker in file
 =======
 ^~~~~~~
./src/map.hpp:49:22: error: no matching function for call to ‘PlayerController::PlayerController()’
     PlayerController Player1Controller, Player2Controller;
                      ^~~~~~~~~~~~~~~~~
In file included from ./src/map.hpp:13:0,
                 from ./src/playstate.hpp:4,
                 from ./src/app.cpp:9:
./src/playercontroller.hpp:11:5: note: candidate: PlayerController::PlayerController(GameWindow&)
     PlayerController(GameWindow &input);
     ^~~~~~~~~~~~~~~~
./src/playercontroller.hpp:11:5: note:   candidate expects 1 argument, 0 provided
In file included from ./src/playstate.hpp:4:0,
                 from ./src/app.cpp:9:
./src/map.hpp:49:41: error: no matching function for call to ‘PlayerController::PlayerController()’
     PlayerController Player1Controller, Player2Controller;
                                         ^~~~~~~~~~~~~~~~~
In file included from ./src/map.hpp:13:0,
                 from ./src/playstate.hpp:4,
                 from ./src/app.cpp:9:
./src/playercontroller.hpp:11:5: note: candidate: PlayerController::PlayerController(GameWindow&)
     PlayerController(GameWindow &input);
     ^~~~~~~~~~~~~~~~
./src/playercontroller.hpp:11:5: note:   candidate expects 1 argument, 0 provided
In file included from ./src/playstate.hpp:4:0,
                 from ./src/app.cpp:9:
./src/map.hpp:50:1: error: expected declaration before ‘}’ token
 };
 ^
In file included from ./src/map.cpp:1:0:
./src/map.hpp:43:1: error: version control conflict marker in file
 <<<<<<< HEAD
 ^~~~~~~
./src/map.hpp: In member function ‘Physics& Map::physics()’:
./src/map.hpp:32:30: error: ‘ThePhysics’ was not declared in this scope
  Physics &physics() { return ThePhysics; }
                              ^~~~~~~~~~
./src/map.hpp: In member function ‘PlayerController& Map::player1()’:
./src/map.hpp:34:42: error: ‘Player1Controller’ was not declared in this scope
     PlayerController &player1() { return Player1Controller; }
                                          ^~~~~~~~~~~~~~~~~
./src/map.hpp: In member function ‘PlayerController& Map::player2()’:
./src/map.hpp:35:42: error: ‘Player2Controller’ was not declared in this scope
     PlayerController &player2() { return Player2Controller; }
                                          ^~~~~~~~~~~~~~~~~
./src/map.hpp: At global scope:
./src/map.hpp:45:1: error: version control conflict marker in file
 =======
 ^~~~~~~
./src/map.hpp:49:22: error: no matching function for call to ‘PlayerController::PlayerController()’
     PlayerController Player1Controller, Player2Controller;
                      ^~~~~~~~~~~~~~~~~
In file included from ./src/map.hpp:13:0,
                 from ./src/map.cpp:1:
./src/playercontroller.hpp:11:5: note: candidate: PlayerController::PlayerController(GameWindow&)
     PlayerController(GameWindow &input);
     ^~~~~~~~~~~~~~~~
./src/playercontroller.hpp:11:5: note:   candidate expects 1 argument, 0 provided
In file included from ./src/map.cpp:1:0:
./src/map.hpp:49:41: error: no matching function for call to ‘PlayerController::PlayerController()’
     PlayerController Player1Controller, Player2Controller;
                                         ^~~~~~~~~~~~~~~~~
In file included from ./src/map.hpp:13:0,
                 from ./src/map.cpp:1:
./src/playercontroller.hpp:11:5: note: candidate: PlayerController::PlayerController(GameWindow&)
     PlayerController(GameWindow &input);
     ^~~~~~~~~~~~~~~~
./src/playercontroller.hpp:11:5: note:   candidate expects 1 argument, 0 provided
In file included from ./src/map.cpp:1:0:
./src/map.hpp:50:1: error: expected declaration before ‘}’ token
 };
 ^
./src/physics.cpp:1:9: warning: #pragma once in main file
 #pragma once
         ^~~~
In file included from ./src/platform.cpp:5:0:
./src/map.hpp:43:1: error: version control conflict marker in file
 <<<<<<< HEAD
 ^~~~~~~
./src/map.hpp: In member function ‘Physics& Map::physics()’:
./src/map.hpp:32:30: error: ‘ThePhysics’ was not declared in this scope
  Physics &physics() { return ThePhysics; }
                              ^~~~~~~~~~
./src/map.hpp: In member function ‘PlayerController& Map::player1()’:
./src/map.hpp:34:42: error: ‘Player1Controller’ was not declared in this scope
     PlayerController &player1() { return Player1Controller; }
                                          ^~~~~~~~~~~~~~~~~
./src/map.hpp: In member function ‘PlayerController& Map::player2()’:
./src/map.hpp:35:42: error: ‘Player2Controller’ was not declared in this scope
     PlayerController &player2() { return Player2Controller; }
                                          ^~~~~~~~~~~~~~~~~
./src/map.hpp: At global scope:
./src/map.hpp:45:1: error: version control conflict marker in file
 =======
 ^~~~~~~
./src/map.hpp:49:22: error: no matching function for call to ‘PlayerController::PlayerController()’
     PlayerController Player1Controller, Player2Controller;
                      ^~~~~~~~~~~~~~~~~
In file included from ./src/map.hpp:13:0,
                 from ./src/platform.cpp:5:
./src/playercontroller.hpp:11:5: note: candidate: PlayerController::PlayerController(GameWindow&)
     PlayerController(GameWindow &input);
     ^~~~~~~~~~~~~~~~
./src/playercontroller.hpp:11:5: note:   candidate expects 1 argument, 0 provided
In file included from ./src/platform.cpp:5:0:
./src/map.hpp:49:41: error: no matching function for call to ‘PlayerController::PlayerController()’
     PlayerController Player1Controller, Player2Controller;
                                         ^~~~~~~~~~~~~~~~~
In file included from ./src/map.hpp:13:0,
                 from ./src/platform.cpp:5:
./src/playercontroller.hpp:11:5: note: candidate: PlayerController::PlayerController(GameWindow&)
     PlayerController(GameWindow &input);
     ^~~~~~~~~~~~~~~~
./src/playercontroller.hpp:11:5: note:   candidate expects 1 argument, 0 provided
In file included from ./src/platform.cpp:5:0:
./src/map.hpp:50:1: error: expected declaration before ‘}’ token
 };
 ^
In file included from ./src/player.cpp:1:0:
./src/player.hpp:3:1: error: version control conflict marker in file
 <<<<<<< HEAD
 ^~~~~~~
In file included from /usr/include/SFML/System/Clock.hpp:32:0,
                 from /usr/include/SFML/System.hpp:33,
                 from /usr/include/SFML/Window.hpp:32,
                 from ./src/sfml/Graphics.hpp:32,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/System/Time.hpp:70:5: error: ‘Int32’ does not name a type
     Int32 asMilliseconds() const;
     ^~~~~
/usr/include/SFML/System/Time.hpp:80:5: error: ‘Int64’ does not name a type
     Int64 asMicroseconds() const;
     ^~~~~
/usr/include/SFML/System/Time.hpp:90:46: error: ‘Int32’ has not been declared
     friend SFML_SYSTEM_API Time milliseconds(Int32);
                                              ^~~~~
/usr/include/SFML/System/Time.hpp:91:46: error: ‘Int64’ has not been declared
     friend SFML_SYSTEM_API Time microseconds(Int64);
                                              ^~~~~
/usr/include/SFML/System/Time.hpp:102:25: error: expected ‘)’ before ‘microseconds’
     explicit Time(Int64 microseconds);
                         ^~~~~~~~~~~~
/usr/include/SFML/System/Time.hpp:109:5: error: ‘Int64’ does not name a type
     Int64 m_microseconds; ///< Time value stored as microseconds
     ^~~~~
/usr/include/SFML/System/Time.hpp:136:35: error: ‘sf::Time sf::milliseconds’ redeclared as different kind of symbol
 SFML_SYSTEM_API Time milliseconds(Int32 amount);
                                   ^~~~~
/usr/include/SFML/System/Time.hpp:90:33: note: previous declaration ‘sf::Time sf::milliseconds(int)’
     friend SFML_SYSTEM_API Time milliseconds(Int32);
                                 ^~~~~~~~~~~~
/usr/include/SFML/System/Time.hpp:136:35: error: ‘Int32’ was not declared in this scope
 SFML_SYSTEM_API Time milliseconds(Int32 amount);
                                   ^~~~~
/usr/include/SFML/System/Time.hpp:149:35: error: ‘sf::Time sf::microseconds’ redeclared as different kind of symbol
 SFML_SYSTEM_API Time microseconds(Int64 amount);
                                   ^~~~~
/usr/include/SFML/System/Time.hpp:91:33: note: previous declaration ‘sf::Time sf::microseconds(int)’
     friend SFML_SYSTEM_API Time microseconds(Int64);
                                 ^~~~~~~~~~~~
/usr/include/SFML/System/Time.hpp:149:35: error: ‘Int64’ was not declared in this scope
 SFML_SYSTEM_API Time microseconds(Int64 amount);
                                   ^~~~~
/usr/include/SFML/System/Time.hpp:304:44: error: ‘Int64’ has not been declared
 SFML_SYSTEM_API Time operator *(Time left, Int64 right);
                                            ^~~~~
/usr/include/SFML/System/Time.hpp:328:33: error: declaration of ‘operator*’ as non-function
 SFML_SYSTEM_API Time operator *(Int64 left, Time right);
                                 ^~~~~
/usr/include/SFML/System/Time.hpp:328:33: error: ‘Int64’ was not declared in this scope
/usr/include/SFML/System/Time.hpp:328:50: error: expected primary-expression before ‘right’
 SFML_SYSTEM_API Time operator *(Int64 left, Time right);
                                                  ^~~~~
/usr/include/SFML/System/Time.hpp:352:47: error: ‘Int64’ has not been declared
 SFML_SYSTEM_API Time& operator *=(Time& left, Int64 right);
                                               ^~~~~
/usr/include/SFML/System/Time.hpp:376:44: error: ‘Int64’ has not been declared
 SFML_SYSTEM_API Time operator /(Time left, Int64 right);
                                            ^~~~~
/usr/include/SFML/System/Time.hpp:400:47: error: ‘Int64’ has not been declared
 SFML_SYSTEM_API Time& operator /=(Time& left, Int64 right);
                                               ^~~~~
In file included from /usr/include/SFML/System/FileInputStream.hpp:33:0,
                 from /usr/include/SFML/System.hpp:35,
                 from /usr/include/SFML/Window.hpp:32,
                 from ./src/sfml/Graphics.hpp:32,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/System/InputStream.hpp:63:13: error: ‘Int64’ does not name a type
     virtual Int64 read(void* data, Int64 size) = 0;
             ^~~~~
/usr/include/SFML/System/InputStream.hpp:73:13: error: ‘Int64’ does not name a type
     virtual Int64 seek(Int64 position) = 0;
             ^~~~~
/usr/include/SFML/System/InputStream.hpp:81:13: error: ‘Int64’ does not name a type
     virtual Int64 tell() = 0;
             ^~~~~
/usr/include/SFML/System/InputStream.hpp:89:13: error: ‘Int64’ does not name a type
     virtual Int64 getSize() = 0;
             ^~~~~
In file included from /usr/include/SFML/System.hpp:35:0,
                 from /usr/include/SFML/Window.hpp:32,
                 from ./src/sfml/Graphics.hpp:32,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/System/FileInputStream.hpp:92:13: error: ‘Int64’ does not name a type
     virtual Int64 read(void* data, Int64 size);
             ^~~~~
/usr/include/SFML/System/FileInputStream.hpp:102:13: error: ‘Int64’ does not name a type
     virtual Int64 seek(Int64 position);
             ^~~~~
/usr/include/SFML/System/FileInputStream.hpp:110:13: error: ‘Int64’ does not name a type
     virtual Int64 tell();
             ^~~~~
/usr/include/SFML/System/FileInputStream.hpp:118:13: error: ‘Int64’ does not name a type
     virtual Int64 getSize();
             ^~~~~
In file included from /usr/include/SFML/System.hpp:38:0,
                 from /usr/include/SFML/Window.hpp:32,
                 from ./src/sfml/Graphics.hpp:32,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/System/MemoryInputStream.hpp:74:13: error: ‘Int64’ does not name a type
     virtual Int64 read(void* data, Int64 size);
             ^~~~~
/usr/include/SFML/System/MemoryInputStream.hpp:84:13: error: ‘Int64’ does not name a type
     virtual Int64 seek(Int64 position);
             ^~~~~
/usr/include/SFML/System/MemoryInputStream.hpp:92:13: error: ‘Int64’ does not name a type
     virtual Int64 tell();
             ^~~~~
/usr/include/SFML/System/MemoryInputStream.hpp:100:13: error: ‘Int64’ does not name a type
     virtual Int64 getSize();
             ^~~~~
/usr/include/SFML/System/MemoryInputStream.hpp:108:5: error: ‘Int64’ does not name a type
     Int64       m_size;   ///< Total size of the data
     ^~~~~
/usr/include/SFML/System/MemoryInputStream.hpp:109:5: error: ‘Int64’ does not name a type
     Int64       m_offset; ///< Current reading position
     ^~~~~
In file included from /usr/include/SFML/System/String.hpp:32:0,
                 from /usr/include/SFML/System.hpp:42,
                 from /usr/include/SFML/Window.hpp:32,
                 from ./src/sfml/Graphics.hpp:32,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/System/Utf.hpp:67:40: error: ‘Uint32’ has not been declared
     static In decode(In begin, In end, Uint32& output, Uint32 replacement = 0);
                                        ^~~~~~
/usr/include/SFML/System/Utf.hpp:67:56: error: ‘Uint32’ has not been declared
     static In decode(In begin, In end, Uint32& output, Uint32 replacement = 0);
                                                        ^~~~~~
/usr/include/SFML/System/Utf.hpp:83:23: error: ‘Uint32’ has not been declared
     static Out encode(Uint32 input, Out output, Uint8 replacement = 0);
                       ^~~~~~
/usr/include/SFML/System/Utf.hpp:83:49: error: ‘Uint8’ has not been declared
     static Out encode(Uint32 input, Out output, Uint8 replacement = 0);
                                                 ^~~~~
/usr/include/SFML/System/Utf.hpp:274:40: error: ‘Uint32’ has not been declared
     static In decode(In begin, In end, Uint32& output, Uint32 replacement = 0);
                                        ^~~~~~
/usr/include/SFML/System/Utf.hpp:274:56: error: ‘Uint32’ has not been declared
     static In decode(In begin, In end, Uint32& output, Uint32 replacement = 0);
                                                        ^~~~~~
/usr/include/SFML/System/Utf.hpp:290:23: error: ‘Uint32’ has not been declared
     static Out encode(Uint32 input, Out output, Uint16 replacement = 0);
                       ^~~~~~
/usr/include/SFML/System/Utf.hpp:290:49: error: ‘Uint16’ has not been declared
     static Out encode(Uint32 input, Out output, Uint16 replacement = 0);
                                                 ^~~~~~
/usr/include/SFML/System/Utf.hpp:482:40: error: ‘Uint32’ has not been declared
     static In decode(In begin, In end, Uint32& output, Uint32 replacement = 0);
                                        ^~~~~~
/usr/include/SFML/System/Utf.hpp:482:56: error: ‘Uint32’ has not been declared
     static In decode(In begin, In end, Uint32& output, Uint32 replacement = 0);
                                                        ^~~~~~
/usr/include/SFML/System/Utf.hpp:499:23: error: ‘Uint32’ has not been declared
     static Out encode(Uint32 input, Out output, Uint32 replacement = 0);
                       ^~~~~~
/usr/include/SFML/System/Utf.hpp:499:49: error: ‘Uint32’ has not been declared
     static Out encode(Uint32 input, Out output, Uint32 replacement = 0);
                                                 ^~~~~~
/usr/include/SFML/System/Utf.hpp:678:12: error: ‘Uint32’ does not name a type
     static Uint32 decodeAnsi(In input, const std::locale& locale = std::locale());
            ^~~~~~
/usr/include/SFML/System/Utf.hpp:693:12: error: ‘Uint32’ does not name a type
     static Uint32 decodeWide(In input);
            ^~~~~~
/usr/include/SFML/System/Utf.hpp:711:27: error: ‘Uint32’ has not been declared
     static Out encodeAnsi(Uint32 codepoint, Out output, char replacement = 0, const std::locale& locale = std::locale());
                           ^~~~~~
/usr/include/SFML/System/Utf.hpp:728:27: error: ‘Uint32’ has not been declared
     static Out encodeWide(Uint32 codepoint, Out output, wchar_t replacement = 0);
                           ^~~~~~
In file included from /usr/include/SFML/System/Utf.hpp:731:0,
                 from /usr/include/SFML/System/String.hpp:32,
                 from /usr/include/SFML/System.hpp:42,
                 from /usr/include/SFML/Window.hpp:32,
                 from ./src/sfml/Graphics.hpp:32,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/System/Utf.inl:39:37: error: ‘Uint32’ has not been declared
 In Utf<8>::decode(In begin, In end, Uint32& output, Uint32 replacement)
                                     ^~~~~~
/usr/include/SFML/System/Utf.inl:39:53: error: ‘Uint32’ has not been declared
 In Utf<8>::decode(In begin, In end, Uint32& output, Uint32 replacement)
                                                     ^~~~~~
/usr/include/SFML/System/Utf.inl: In static member function ‘static In sf::Utf<8u>::decode(In, In, int&, int)’:
/usr/include/SFML/System/Utf.inl:53:18: error: ‘Uint32’ does not name a type
     static const Uint32 offsets[6] =
                  ^~~~~~
/usr/include/SFML/System/Utf.inl:59:46: error: ‘Uint8’ does not name a type
     int trailingBytes = trailing[static_cast<Uint8>(*begin)];
                                              ^~~~~
/usr/include/SFML/System/Utf.inl:65:43: error: ‘Uint8’ does not name a type
             case 5: output += static_cast<Uint8>(*begin++); output <<= 6;
                                           ^~~~~
/usr/include/SFML/System/Utf.inl:66:43: error: ‘Uint8’ does not name a type
             case 4: output += static_cast<Uint8>(*begin++); output <<= 6;
                                           ^~~~~
/usr/include/SFML/System/Utf.inl:67:43: error: ‘Uint8’ does not name a type
             case 3: output += static_cast<Uint8>(*begin++); output <<= 6;
                                           ^~~~~
/usr/include/SFML/System/Utf.inl:68:43: error: ‘Uint8’ does not name a type
             case 2: output += static_cast<Uint8>(*begin++); output <<= 6;
                                           ^~~~~
/usr/include/SFML/System/Utf.inl:69:43: error: ‘Uint8’ does not name a type
             case 1: output += static_cast<Uint8>(*begin++); output <<= 6;
                                           ^~~~~
/usr/include/SFML/System/Utf.inl:70:43: error: ‘Uint8’ does not name a type
             case 0: output += static_cast<Uint8>(*begin++);
                                           ^~~~~
/usr/include/SFML/System/Utf.inl:72:19: error: ‘offsets’ was not declared in this scope
         output -= offsets[trailingBytes];
                   ^~~~~~~
/usr/include/SFML/System/Utf.inl: At global scope:
/usr/include/SFML/System/Utf.inl:87:20: error: ‘Out sf::Utf<8u>::encode’ is not a static data member of ‘class sf::Utf<8u>’
 Out Utf<8>::encode(Uint32 input, Out output, Uint8 replacement)
                    ^~~~~~
/usr/include/SFML/System/Utf.inl:87:20: error: template definition of non-template ‘Out sf::Utf<8u>::encode’
/usr/include/SFML/System/Utf.inl:87:20: error: ‘Uint32’ was not declared in this scope
/usr/include/SFML/System/Utf.inl:87:38: error: expected primary-expression before ‘output’
 Out Utf<8>::encode(Uint32 input, Out output, Uint8 replacement)
                                      ^~~~~~
/usr/include/SFML/System/Utf.inl:87:46: error: ‘Uint8’ was not declared in this scope
 Out Utf<8>::encode(Uint32 input, Out output, Uint8 replacement)
                                              ^~~~~
/usr/include/SFML/System/Utf.inl: In static member function ‘static In sf::Utf<8u>::next(In, In)’:
/usr/include/SFML/System/Utf.inl:135:5: error: ‘Uint32’ was not declared in this scope
     Uint32 codepoint;
     ^~~~~~
/usr/include/SFML/System/Utf.inl:136:31: error: ‘codepoint’ was not declared in this scope
     return decode(begin, end, codepoint);
                               ^~~~~~~~~
/usr/include/SFML/System/Utf.inl: In static member function ‘static Out sf::Utf<8u>::fromAnsi(In, In, Out, const std::locale&)’:
/usr/include/SFML/System/Utf.inl:161:9: error: ‘Uint32’ was not declared in this scope
         Uint32 codepoint = Utf<32>::decodeAnsi(*begin++, locale);
         ^~~~~~
/usr/include/SFML/System/Utf.inl:162:25: error: ‘codepoint’ was not declared in this scope
         output = encode(codepoint, output);
                         ^~~~~~~~~
/usr/include/SFML/System/Utf.inl: In static member function ‘static Out sf::Utf<8u>::fromWide(In, In, Out)’:
/usr/include/SFML/System/Utf.inl:175:9: error: ‘Uint32’ was not declared in this scope
         Uint32 codepoint = Utf<32>::decodeWide(*begin++);
         ^~~~~~
/usr/include/SFML/System/Utf.inl:176:25: error: ‘codepoint’ was not declared in this scope
         output = encode(codepoint, output);
                         ^~~~~~~~~
/usr/include/SFML/System/Utf.inl: In static member function ‘static Out sf::Utf<8u>::toAnsi(In, In, Out, char, const std::locale&)’:
/usr/include/SFML/System/Utf.inl:202:9: error: ‘Uint32’ was not declared in this scope
         Uint32 codepoint;
         ^~~~~~
/usr/include/SFML/System/Utf.inl:203:36: error: ‘codepoint’ was not declared in this scope
         begin = decode(begin, end, codepoint);
                                    ^~~~~~~~~
/usr/include/SFML/System/Utf.inl: In static member function ‘static Out sf::Utf<8u>::toWide(In, In, Out, wchar_t)’:
/usr/include/SFML/System/Utf.inl:217:9: error: ‘Uint32’ was not declared in this scope
         Uint32 codepoint;
         ^~~~~~
/usr/include/SFML/System/Utf.inl:218:36: error: ‘codepoint’ was not declared in this scope
         begin = decode(begin, end, codepoint);
                                    ^~~~~~~~~
/usr/include/SFML/System/Utf.inl: In static member function ‘static Out sf::Utf<8u>::toLatin1(In, In, Out, char)’:
/usr/include/SFML/System/Utf.inl:234:9: error: ‘Uint32’ was not declared in this scope
         Uint32 codepoint;
         ^~~~~~
/usr/include/SFML/System/Utf.inl:235:36: error: ‘codepoint’ was not declared in this scope
         begin = decode(begin, end, codepoint);
                                    ^~~~~~~~~
/usr/include/SFML/System/Utf.inl: In static member function ‘static Out sf::Utf<8u>::toUtf16(In, In, Out)’:
/usr/include/SFML/System/Utf.inl:257:9: error: ‘Uint32’ was not declared in this scope
         Uint32 codepoint;
         ^~~~~~
/usr/include/SFML/System/Utf.inl:258:36: error: ‘codepoint’ was not declared in this scope
         begin = decode(begin, end, codepoint);
                                    ^~~~~~~~~
/usr/include/SFML/System/Utf.inl: In static member function ‘static Out sf::Utf<8u>::toUtf32(In, In, Out)’:
/usr/include/SFML/System/Utf.inl:272:9: error: ‘Uint32’ was not declared in this scope
         Uint32 codepoint;
         ^~~~~~
/usr/include/SFML/System/Utf.inl:273:36: error: ‘codepoint’ was not declared in this scope
         begin = decode(begin, end, codepoint);
                                    ^~~~~~~~~
/usr/include/SFML/System/Utf.inl: At global scope:
/usr/include/SFML/System/Utf.inl:283:38: error: ‘Uint32’ has not been declared
 In Utf<16>::decode(In begin, In end, Uint32& output, Uint32 replacement)
                                      ^~~~~~
/usr/include/SFML/System/Utf.inl:283:54: error: ‘Uint32’ has not been declared
 In Utf<16>::decode(In begin, In end, Uint32& output, Uint32 replacement)
                                                      ^~~~~~
/usr/include/SFML/System/Utf.inl: In static member function ‘static In sf::Utf<16u>::decode(In, In, int&, int)’:
/usr/include/SFML/System/Utf.inl:285:5: error: ‘Uint16’ was not declared in this scope
     Uint16 first = *begin++;
     ^~~~~~
/usr/include/SFML/System/Utf.inl:288:10: error: ‘first’ was not declared in this scope
     if ((first >= 0xD800) && (first <= 0xDBFF))
          ^~~~~
/usr/include/SFML/System/Utf.inl:292:13: error: ‘Uint32’ was not declared in this scope
             Uint32 second = *begin++;
             ^~~~~~
/usr/include/SFML/System/Utf.inl:293:18: error: ‘second’ was not declared in this scope
             if ((second >= 0xDC00) && (second <= 0xDFFF))
                  ^~~~~~
/usr/include/SFML/System/Utf.inl:296:38: error: ‘Uint32’ does not name a type
                 output = static_cast<Uint32>(((first - 0xD800) << 10) + (second - 0xDC00) + 0x0010000);
                                      ^~~~~~
/usr/include/SFML/System/Utf.inl: At global scope:
/usr/include/SFML/System/Utf.inl:323:21: error: ‘Out sf::Utf<16u>::encode’ is not a static data member of ‘class sf::Utf<16u>’
 Out Utf<16>::encode(Uint32 input, Out output, Uint16 replacement)
                     ^~~~~~
/usr/include/SFML/System/Utf.inl:323:21: error: template definition of non-template ‘Out sf::Utf<16u>::encode’
/usr/include/SFML/System/Utf.inl:323:21: error: ‘Uint32’ was not declared in this scope
/usr/include/SFML/System/Utf.inl:323:39: error: expected primary-expression before ‘output’
 Out Utf<16>::encode(Uint32 input, Out output, Uint16 replacement)
                                       ^~~~~~
/usr/include/SFML/System/Utf.inl:323:47: error: ‘Uint16’ was not declared in this scope
 Out Utf<16>::encode(Uint32 input, Out output, Uint16 replacement)
                                               ^~~~~~
/usr/include/SFML/System/Utf.inl: In static member function ‘static In sf::Utf<16u>::next(In, In)’:
/usr/include/SFML/System/Utf.inl:362:5: error: ‘Uint32’ was not declared in this scope
     Uint32 codepoint;
     ^~~~~~
/usr/include/SFML/System/Utf.inl:363:31: error: ‘codepoint’ was not declared in this scope
     return decode(begin, end, codepoint);
                               ^~~~~~~~~
/usr/include/SFML/System/Utf.inl: In static member function ‘static Out sf::Utf<16u>::fromAnsi(In, In, Out, const std::locale&)’:
/usr/include/SFML/System/Utf.inl:388:9: error: ‘Uint32’ was not declared in this scope
         Uint32 codepoint = Utf<32>::decodeAnsi(*begin++, locale);
         ^~~~~~
/usr/include/SFML/System/Utf.inl:389:25: error: ‘codepoint’ was not declared in this scope
         output = encode(codepoint, output);
                         ^~~~~~~~~
/usr/include/SFML/System/Utf.inl: In static member function ‘static Out sf::Utf<16u>::fromWide(In, In, Out)’:
/usr/include/SFML/System/Utf.inl:402:9: error: ‘Uint32’ was not declared in this scope
         Uint32 codepoint = Utf<32>::decodeWide(*begin++);
         ^~~~~~
/usr/include/SFML/System/Utf.inl:403:25: error: ‘codepoint’ was not declared in this scope
         output = encode(codepoint, output);
                         ^~~~~~~~~
/usr/include/SFML/System/Utf.inl: In static member function ‘static Out sf::Utf<16u>::toAnsi(In, In, Out, char, const std::locale&)’:
/usr/include/SFML/System/Utf.inl:426:9: error: ‘Uint32’ was not declared in this scope
         Uint32 codepoint;
         ^~~~~~
/usr/include/SFML/System/Utf.inl:427:36: error: ‘codepoint’ was not declared in this scope
         begin = decode(begin, end, codepoint);
                                    ^~~~~~~~~
/usr/include/SFML/System/Utf.inl: In static member function ‘static Out sf::Utf<16u>::toWide(In, In, Out, wchar_t)’:
/usr/include/SFML/System/Utf.inl:441:9: error: ‘Uint32’ was not declared in this scope
         Uint32 codepoint;
         ^~~~~~
/usr/include/SFML/System/Utf.inl:442:36: error: ‘codepoint’ was not declared in this scope
         begin = decode(begin, end, codepoint);
                                    ^~~~~~~~~
/usr/include/SFML/System/Utf.inl: In static member function ‘static Out sf::Utf<16u>::toUtf8(In, In, Out)’:
/usr/include/SFML/System/Utf.inl:472:9: error: ‘Uint32’ was not declared in this scope
         Uint32 codepoint;
         ^~~~~~
/usr/include/SFML/System/Utf.inl:473:36: error: ‘codepoint’ was not declared in this scope
         begin = decode(begin, end, codepoint);
                                    ^~~~~~~~~
/usr/include/SFML/System/Utf.inl: In static member function ‘static Out sf::Utf<16u>::toUtf32(In, In, Out)’:
/usr/include/SFML/System/Utf.inl:495:9: error: ‘Uint32’ was not declared in this scope
         Uint32 codepoint;
         ^~~~~~
/usr/include/SFML/System/Utf.inl:496:36: error: ‘codepoint’ was not declared in this scope
         begin = decode(begin, end, codepoint);
                                    ^~~~~~~~~
/usr/include/SFML/System/Utf.inl: At global scope:
/usr/include/SFML/System/Utf.inl:506:42: error: ‘Uint32’ has not been declared
 In Utf<32>::decode(In begin, In /*end*/, Uint32& output, Uint32 /*replacement*/)
                                          ^~~~~~
/usr/include/SFML/System/Utf.inl:506:58: error: ‘Uint32’ has not been declared
 In Utf<32>::decode(In begin, In /*end*/, Uint32& output, Uint32 /*replacement*/)
                                                          ^~~~~~
/usr/include/SFML/System/Utf.inl:515:21: error: ‘Out sf::Utf<32u>::encode’ is not a static data member of ‘class sf::Utf<32u>’
 Out Utf<32>::encode(Uint32 input, Out output, Uint32 /*replacement*/)
                     ^~~~~~
/usr/include/SFML/System/Utf.inl:515:21: error: template definition of non-template ‘Out sf::Utf<32u>::encode’
/usr/include/SFML/System/Utf.inl:515:21: error: ‘Uint32’ was not declared in this scope
/usr/include/SFML/System/Utf.inl:515:39: error: expected primary-expression before ‘output’
 Out Utf<32>::encode(Uint32 input, Out output, Uint32 /*replacement*/)
                                       ^~~~~~
/usr/include/SFML/System/Utf.inl:515:47: error: ‘Uint32’ was not declared in this scope
 Out Utf<32>::encode(Uint32 input, Out output, Uint32 /*replacement*/)
                                               ^~~~~~
/usr/include/SFML/System/Utf.inl:639:1: error: ‘Uint32’ does not name a type
 Uint32 Utf<32>::decodeAnsi(In input, const std::locale& locale)
 ^~~~~~
/usr/include/SFML/System/Utf.inl:670:1: error: ‘Uint32’ does not name a type
 Uint32 Utf<32>::decodeWide(In input)
 ^~~~~~
/usr/include/SFML/System/Utf.inl:684:25: error: ‘Out sf::Utf<32u>::encodeAnsi’ is not a static data member of ‘class sf::Utf<32u>’
 Out Utf<32>::encodeAnsi(Uint32 codepoint, Out output, char replacement, const std::locale& locale)
                         ^~~~~~
/usr/include/SFML/System/Utf.inl:684:25: error: template definition of non-template ‘Out sf::Utf<32u>::encodeAnsi’
/usr/include/SFML/System/Utf.inl:684:25: error: ‘Uint32’ was not declared in this scope
/usr/include/SFML/System/Utf.inl:684:47: error: expected primary-expression before ‘output’
 Out Utf<32>::encodeAnsi(Uint32 codepoint, Out output, char replacement, const std::locale& locale)
                                               ^~~~~~
/usr/include/SFML/System/Utf.inl:684:55: error: expected primary-expression before ‘char’
 Out Utf<32>::encodeAnsi(Uint32 codepoint, Out output, char replacement, const std::locale& locale)
                                                       ^~~~
/usr/include/SFML/System/Utf.inl:684:73: error: expected primary-expression before ‘const’
 Out Utf<32>::encodeAnsi(Uint32 codepoint, Out output, char replacement, const std::locale& locale)
                                                                         ^~~~~
/usr/include/SFML/System/Utf.inl:721:25: error: ‘Out sf::Utf<32u>::encodeWide’ is not a static data member of ‘class sf::Utf<32u>’
 Out Utf<32>::encodeWide(Uint32 codepoint, Out output, wchar_t replacement)
                         ^~~~~~
/usr/include/SFML/System/Utf.inl:721:25: error: template definition of non-template ‘Out sf::Utf<32u>::encodeWide’
/usr/include/SFML/System/Utf.inl:721:25: error: ‘Uint32’ was not declared in this scope
/usr/include/SFML/System/Utf.inl:721:47: error: expected primary-expression before ‘output’
 Out Utf<32>::encodeWide(Uint32 codepoint, Out output, wchar_t replacement)
                                               ^~~~~~
/usr/include/SFML/System/Utf.inl:721:55: error: expected primary-expression before ‘wchar_t’
 Out Utf<32>::encodeWide(Uint32 codepoint, Out output, wchar_t replacement)
                                                       ^~~~~~~
In file included from /usr/include/SFML/System.hpp:42:0,
                 from /usr/include/SFML/Window.hpp:32,
                 from ./src/sfml/Graphics.hpp:32,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/System/String.hpp:52:31: error: ‘Uint32’ was not declared in this scope
     typedef std::basic_string<Uint32>::iterator       Iterator;      ///< Iterator type
                               ^~~~~~
/usr/include/SFML/System/String.hpp:52:37: error: template argument 1 is invalid
     typedef std::basic_string<Uint32>::iterator       Iterator;      ///< Iterator type
                                     ^
/usr/include/SFML/System/String.hpp:52:37: error: template argument 2 is invalid
/usr/include/SFML/System/String.hpp:52:37: error: template argument 3 is invalid
/usr/include/SFML/System/String.hpp:52:40: error: expected ‘;’ at end of member declaration
     typedef std::basic_string<Uint32>::iterator       Iterator;      ///< Iterator type
                                        ^~~~~~~~
/usr/include/SFML/System/String.hpp:52:55: error: ‘Iterator’ does not name a type
     typedef std::basic_string<Uint32>::iterator       Iterator;      ///< Iterator type
                                                       ^~~~~~~~
/usr/include/SFML/System/String.hpp:53:31: error: ‘Uint32’ was not declared in this scope
     typedef std::basic_string<Uint32>::const_iterator ConstIterator; ///< Read-only iterator type
                               ^~~~~~
/usr/include/SFML/System/String.hpp:53:37: error: template argument 1 is invalid
     typedef std::basic_string<Uint32>::const_iterator ConstIterator; ///< Read-only iterator type
                                     ^
/usr/include/SFML/System/String.hpp:53:37: error: template argument 2 is invalid
/usr/include/SFML/System/String.hpp:53:37: error: template argument 3 is invalid
/usr/include/SFML/System/String.hpp:53:40: error: expected ‘;’ at end of member declaration
     typedef std::basic_string<Uint32>::const_iterator ConstIterator; ///< Read-only iterator type
                                        ^~~~~~~~~~~~~~
/usr/include/SFML/System/String.hpp:53:55: error: ‘ConstIterator’ does not name a type
     typedef std::basic_string<Uint32>::const_iterator ConstIterator; ///< Read-only iterator type
                                                       ^~~~~~~~~~~~~
/usr/include/SFML/System/String.hpp:94:19: error: expected ‘)’ before ‘utf32Char’
     String(Uint32 utf32Char);
                   ^~~~~~~~~
/usr/include/SFML/System/String.hpp:142:18: error: ‘Uint32’ does not name a type
     String(const Uint32* utf32String);
                  ^~~~~~
/usr/include/SFML/System/String.hpp:150:36: error: ‘Uint32’ was not declared in this scope
     String(const std::basic_string<Uint32>& utf32String);
                                    ^~~~~~
/usr/include/SFML/System/String.hpp:150:42: error: template argument 1 is invalid
     String(const std::basic_string<Uint32>& utf32String);
                                          ^
/usr/include/SFML/System/String.hpp:150:42: error: template argument 2 is invalid
/usr/include/SFML/System/String.hpp:150:42: error: template argument 3 is invalid
/usr/include/SFML/System/String.hpp:276:23: error: ‘Uint8’ was not declared in this scope
     std::basic_string<Uint8> toUtf8() const;
                       ^~~~~
/usr/include/SFML/System/String.hpp:276:28: error: template argument 1 is invalid
     std::basic_string<Uint8> toUtf8() const;
                            ^
/usr/include/SFML/System/String.hpp:276:28: error: template argument 2 is invalid
/usr/include/SFML/System/String.hpp:276:28: error: template argument 3 is invalid
/usr/include/SFML/System/String.hpp:286:23: error: ‘Uint16’ was not declared in this scope
     std::basic_string<Uint16> toUtf16() const;
                       ^~~~~~
/usr/include/SFML/System/String.hpp:286:29: error: template argument 1 is invalid
     std::basic_string<Uint16> toUtf16() const;
                             ^
/usr/include/SFML/System/String.hpp:286:29: error: template argument 2 is invalid
/usr/include/SFML/System/String.hpp:286:29: error: template argument 3 is invalid
/usr/include/SFML/System/String.hpp:299:23: error: ‘Uint32’ was not declared in this scope
     std::basic_string<Uint32> toUtf32() const;
                       ^~~~~~
/usr/include/SFML/System/String.hpp:299:29: error: template argument 1 is invalid
     std::basic_string<Uint32> toUtf32() const;
                             ^
/usr/include/SFML/System/String.hpp:299:29: error: template argument 2 is invalid
/usr/include/SFML/System/String.hpp:299:29: error: template argument 3 is invalid
/usr/include/SFML/System/String.hpp:332:5: error: ‘Uint32’ does not name a type
     Uint32 operator [](std::size_t index) const;
     ^~~~~~
/usr/include/SFML/System/String.hpp:345:5: error: ‘Uint32’ does not name a type
     Uint32& operator [](std::size_t index);
     ^~~~~~
/usr/include/SFML/System/String.hpp:469:11: error: ‘Uint32’ does not name a type
     const Uint32* getData() const;
           ^~~~~~
/usr/include/SFML/System/String.hpp:479:5: error: ‘Iterator’ does not name a type
     Iterator begin();
     ^~~~~~~~
/usr/include/SFML/System/String.hpp:489:5: error: ‘ConstIterator’ does not name a type
     ConstIterator begin() const;
     ^~~~~~~~~~~~~
/usr/include/SFML/System/String.hpp:503:5: error: ‘Iterator’ does not name a type
     Iterator end();
     ^~~~~~~~
/usr/include/SFML/System/String.hpp:517:5: error: ‘ConstIterator’ does not name a type
     ConstIterator end() const;
     ^~~~~~~~~~~~~
/usr/include/SFML/System/String.hpp:527:23: error: ‘Uint32’ was not declared in this scope
     std::basic_string<Uint32> m_string; ///< Internal string of UTF-32 characters
                       ^~~~~~
/usr/include/SFML/System/String.hpp:527:29: error: template argument 1 is invalid
     std::basic_string<Uint32> m_string; ///< Internal string of UTF-32 characters
                             ^
/usr/include/SFML/System/String.hpp:527:29: error: template argument 2 is invalid
/usr/include/SFML/System/String.hpp:527:29: error: template argument 3 is invalid
In file included from /usr/include/SFML/System/String.hpp:614:0,
                 from /usr/include/SFML/System.hpp:42,
                 from /usr/include/SFML/Window.hpp:32,
                 from ./src/sfml/Graphics.hpp:32,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/System/String.inl: In static member function ‘static sf::String sf::String::fromUtf32(T, T)’:
/usr/include/SFML/System/String.inl:51:21: error: request for member ‘assign’ in ‘string.m_string’, which is of non-class type ‘int’
     string.m_string.assign(begin, end);
                     ^~~~~~
In file included from /usr/include/SFML/Window/Context.hpp:33:0,
                 from /usr/include/SFML/Window.hpp:33,
                 from ./src/sfml/Graphics.hpp:32,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/Window/ContextSettings.hpp: At global scope:
/usr/include/SFML/Window/ContextSettings.hpp:80:5: error: ‘Uint32’ does not name a type
     Uint32       attributeFlags;    ///< The attribute flags to create the context with
     ^~~~~~
/usr/include/SFML/Window/ContextSettings.hpp: In constructor ‘sf::ContextSettings::ContextSettings(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, bool)’:
/usr/include/SFML/Window/ContextSettings.hpp:67:5: error: class ‘sf::ContextSettings’ does not have any field named ‘attributeFlags’
     attributeFlags   (attributes),
     ^~~~~~~~~~~~~~
In file included from /usr/include/SFML/Window.hpp:35:0,
                 from ./src/sfml/Graphics.hpp:32,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/Window/Event.hpp: At global scope:
/usr/include/SFML/Window/Event.hpp:77:9: error: ‘Uint32’ does not name a type
         Uint32 unicode; ///< UTF-32 Unicode value of the character
         ^~~~~~
In file included from /usr/include/SFML/Window.hpp:42:0,
                 from ./src/sfml/Graphics.hpp:32,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/Window/Window.hpp:89:49: error: ‘Uint32’ has not been declared
     Window(VideoMode mode, const String& title, Uint32 style = Style::Default, const ContextSettings& settings = ContextSettings());
                                                 ^~~~~~
In file included from /usr/include/SFML/Window.hpp:42:0,
                 from ./src/sfml/Graphics.hpp:32,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/Window/Window.hpp:132:54: error: ‘Uint32’ has not been declared
     void create(VideoMode mode, const String& title, Uint32 style = Style::Default, const ContextSettings& settings = ContextSettings());
                                                      ^~~~~~
/usr/include/SFML/Window/Window.hpp:314:65: error: ‘Uint8’ does not name a type
     void setIcon(unsigned int width, unsigned int height, const Uint8* pixels);
                                                                 ^~~~~
In file included from /usr/include/SFML/Graphics/Vertex.hpp:32:0,
                 from /usr/include/SFML/Graphics/VertexArray.hpp:32,
                 from /usr/include/SFML/Graphics/Shape.hpp:34,
                 from /usr/include/SFML/Graphics/CircleShape.hpp:32,
                 from ./src/sfml/Graphics.hpp:34,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/Graphics/Color.hpp:62:17: error: expected ‘)’ before ‘red’
     Color(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha = 255);
                 ^~~
/usr/include/SFML/Graphics/Color.hpp:70:27: error: expected ‘)’ before ‘color’
     explicit Color(Uint32 color);
                           ^~~~~
/usr/include/SFML/Graphics/Color.hpp:78:5: error: ‘Uint32’ does not name a type
     Uint32 toInteger() const;
     ^~~~~~
/usr/include/SFML/Graphics/Color.hpp:96:5: error: ‘Uint8’ does not name a type
     Uint8 r; ///< Red component
     ^~~~~
/usr/include/SFML/Graphics/Color.hpp:97:5: error: ‘Uint8’ does not name a type
     Uint8 g; ///< Green component
     ^~~~~
/usr/include/SFML/Graphics/Color.hpp:98:5: error: ‘Uint8’ does not name a type
     Uint8 b; ///< Blue component
     ^~~~~
/usr/include/SFML/Graphics/Color.hpp:99:5: error: ‘Uint8’ does not name a type
     Uint8 a; ///< Alpha (opacity) component
     ^~~~~
In file included from /usr/include/SFML/Graphics/Texture.hpp:32:0,
                 from /usr/include/SFML/Graphics/Font.hpp:33,
                 from ./src/sfml/Graphics.hpp:38,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/Graphics/Image.hpp:87:64: error: ‘Uint8’ does not name a type
     void create(unsigned int width, unsigned int height, const Uint8* pixels);
                                                                ^~~~~
/usr/include/SFML/Graphics/Image.hpp:177:50: error: ‘Uint8’ has not been declared
     void createMaskFromColor(const Color& color, Uint8 alpha = 0);
                                                  ^~~~~
In file included from /usr/include/SFML/Graphics/Texture.hpp:32:0,
                 from /usr/include/SFML/Graphics/Font.hpp:33,
                 from ./src/sfml/Graphics.hpp:38,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/Graphics/Image.hpp:247:11: error: ‘Uint8’ does not name a type
     const Uint8* getPixelsPtr() const;
           ^~~~~
/usr/include/SFML/Graphics/Image.hpp:267:17: error: ‘Uint8’ was not declared in this scope
     std::vector<Uint8> m_pixels; ///< Pixels of the image
                 ^~~~~
/usr/include/SFML/Graphics/Image.hpp:267:22: error: template argument 1 is invalid
     std::vector<Uint8> m_pixels; ///< Pixels of the image
                      ^
/usr/include/SFML/Graphics/Image.hpp:267:22: error: template argument 2 is invalid
In file included from /usr/include/SFML/Graphics/Texture.hpp:32:0,
                 from /usr/include/SFML/Graphics/Font.hpp:33,
                 from ./src/sfml/Graphics.hpp:38,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/Graphics/Image.hpp:72:92: error: no matching function for call to ‘sf::Color::Color(int, int, int)’
     void create(unsigned int width, unsigned int height, const Color& color = Color(0, 0, 0));
                                                                                            ^
In file included from /usr/include/SFML/Graphics/Vertex.hpp:32:0,
                 from /usr/include/SFML/Graphics/VertexArray.hpp:32,
                 from /usr/include/SFML/Graphics/Shape.hpp:34,
                 from /usr/include/SFML/Graphics/CircleShape.hpp:32,
                 from ./src/sfml/Graphics.hpp:34,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/Graphics/Color.hpp:51:5: note: candidate: sf::Color::Color()
     Color();
     ^~~~~
/usr/include/SFML/Graphics/Color.hpp:51:5: note:   candidate expects 0 arguments, 3 provided
/usr/include/SFML/Graphics/Color.hpp:40:25: note: candidate: constexpr sf::Color::Color(const sf::Color&)
 class SFML_GRAPHICS_API Color
                         ^~~~~
/usr/include/SFML/Graphics/Color.hpp:40:25: note:   candidate expects 1 argument, 3 provided
/usr/include/SFML/Graphics/Color.hpp:40:25: note: candidate: constexpr sf::Color::Color(sf::Color&&)
/usr/include/SFML/Graphics/Color.hpp:40:25: note:   candidate expects 1 argument, 3 provided
In file included from /usr/include/SFML/Graphics/Font.hpp:33:0,
                 from ./src/sfml/Graphics.hpp:38,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/Graphics/Texture.hpp:255:23: error: ‘Uint8’ does not name a type
     void update(const Uint8* pixels);
                       ^~~~~
/usr/include/SFML/Graphics/Texture.hpp:277:23: error: ‘Uint8’ does not name a type
     void update(const Uint8* pixels, unsigned int width, unsigned int height, unsigned int x, unsigned int y);
                       ^~~~~
/usr/include/SFML/Graphics/Texture.hpp:581:5: error: ‘Uint64’ does not name a type
     Uint64       m_cacheId;       ///< Unique number that identifies the texture to the render target's cache
     ^~~~~~
In file included from ./src/sfml/Graphics.hpp:38:0,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/Graphics/Font.hpp:180:18: error: expected ‘;’ at end of member declaration
     const Glyph& getGlyph(Uint32 codePoint, unsigned int characterSize, bool bold, float outlineThickness = 0) const;
                  ^~~~~~~~
/usr/include/SFML/Graphics/Font.hpp:180:34: error: expected ‘)’ before ‘codePoint’
     const Glyph& getGlyph(Uint32 codePoint, unsigned int characterSize, bool bold, float outlineThickness = 0) const;
                                  ^~~~~~~~~
/usr/include/SFML/Graphics/Font.hpp:198:22: error: ‘Uint32’ has not been declared
     float getKerning(Uint32 first, Uint32 second, unsigned int characterSize) const;
                      ^~~~~~
/usr/include/SFML/Graphics/Font.hpp:198:36: error: ‘Uint32’ has not been declared
     float getKerning(Uint32 first, Uint32 second, unsigned int characterSize) const;
                                    ^~~~~~
/usr/include/SFML/Graphics/Font.hpp:284:22: error: ‘Uint64’ was not declared in this scope
     typedef std::map<Uint64, Glyph> GlyphTable; ///< Table mapping a codepoint to its glyph
                      ^~~~~~
/usr/include/SFML/Graphics/Font.hpp:284:35: error: template argument 1 is invalid
     typedef std::map<Uint64, Glyph> GlyphTable; ///< Table mapping a codepoint to its glyph
                                   ^
/usr/include/SFML/Graphics/Font.hpp:284:35: error: template argument 3 is invalid
/usr/include/SFML/Graphics/Font.hpp:284:35: error: template argument 4 is invalid
/usr/include/SFML/Graphics/Font.hpp:317:21: error: ‘Uint32’ has not been declared
     Glyph loadGlyph(Uint32 codePoint, unsigned int characterSize, bool bold, float outlineThickness) const;
                     ^~~~~~
In file included from ./src/sfml/Graphics.hpp:38:0,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/Graphics/Font.hpp:356:25: error: ‘Uint8’ was not declared in this scope
     mutable std::vector<Uint8> m_pixelBuffer; ///< Pixel buffer holding a glyph's pixels before being written to the texture
                         ^~~~~
/usr/include/SFML/Graphics/Font.hpp:356:30: error: template argument 1 is invalid
     mutable std::vector<Uint8> m_pixelBuffer; ///< Pixel buffer holding a glyph's pixels before being written to the texture
                              ^
/usr/include/SFML/Graphics/Font.hpp:356:30: error: template argument 2 is invalid
In file included from ./src/sfml/Graphics.hpp:45:0,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/Graphics/RenderTarget.hpp:408:9: error: ‘Uint64’ does not name a type
         Uint64    lastTextureId;  ///< Cached texture
         ^~~~~~
/usr/include/SFML/Graphics/RenderTarget.hpp:70:55: error: no matching function for call to ‘sf::Color::Color(int, int, int, int)’
     void clear(const Color& color = Color(0, 0, 0, 255));
                                                       ^
In file included from /usr/include/SFML/Graphics/Vertex.hpp:32:0,
                 from /usr/include/SFML/Graphics/VertexArray.hpp:32,
                 from /usr/include/SFML/Graphics/Shape.hpp:34,
                 from /usr/include/SFML/Graphics/CircleShape.hpp:32,
                 from ./src/sfml/Graphics.hpp:34,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/Graphics/Color.hpp:51:5: note: candidate: sf::Color::Color()
     Color();
     ^~~~~
/usr/include/SFML/Graphics/Color.hpp:51:5: note:   candidate expects 0 arguments, 4 provided
/usr/include/SFML/Graphics/Color.hpp:40:25: note: candidate: constexpr sf::Color::Color(const sf::Color&)
 class SFML_GRAPHICS_API Color
                         ^~~~~
/usr/include/SFML/Graphics/Color.hpp:40:25: note:   candidate expects 1 argument, 4 provided
/usr/include/SFML/Graphics/Color.hpp:40:25: note: candidate: constexpr sf::Color::Color(sf::Color&&)
/usr/include/SFML/Graphics/Color.hpp:40:25: note:   candidate expects 1 argument, 4 provided
In file included from ./src/sfml/Graphics.hpp:47:0,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/Graphics/RenderWindow.hpp:76:55: error: ‘Uint32’ has not been declared
     RenderWindow(VideoMode mode, const String& title, Uint32 style = Style::Default, const ContextSettings& settings = ContextSettings());
                                                       ^~~~~~
In file included from ./src/sfml/Graphics.hpp:51:0,
                 from ./src/player.hpp:4,
                 from ./src/player.cpp:1:
/usr/include/SFML/Graphics/Text.hpp:159:19: error: ‘Uint32’ has not been declared
     void setStyle(Uint32 style);
                   ^~~~~~
/usr/include/SFML/Graphics/Text.hpp:271:5: error: ‘Uint32’ does not name a type
     Uint32 getStyle() const;
     ^~~~~~
/usr/include/SFML/Graphics/Text.hpp:388:5: error: ‘Uint32’ does not name a type
     Uint32              m_style;              ///< Text style (see Style enum)
     ^~~~~~
In file included from ./src/player.cpp:1:0:
./src/player.hpp:6:1: error: version control conflict marker in file
 =======
 ^~~~~~~
In file included from ./src/player.hpp:10:0,
                 from ./src/player.cpp:1:
./src/entity.hpp:13:1: error: expected class-name before ‘{’ token
 {
 ^
In file included from ./src/physbox.hpp:5:0,
                 from ./src/player.hpp:11,
                 from ./src/player.cpp:1:
./src/physics.hpp:67:1: error: expected class-name before ‘{’ token
 {
 ^
In file included from ./src/player.cpp:1:0:
./src/player.hpp:38:1: error: version control conflict marker in file
 <<<<<<< HEAD
 ^~~~~~~
./src/player.hpp: In member function ‘Player::Face Player::getFace() const’:
./src/player.hpp:25:35: error: ‘FaceDirection’ was not declared in this scope
     Face getFace() const { return FaceDirection; }
                                   ^~~~~~~~~~~~~
./src/player.hpp: At global scope:
./src/player.hpp:41:1: error: version control conflict marker in file
 =======
 ^~~~~~~
./src/player.hpp:44:5: error: ‘Face’ does not name a type
     Face FaceDirection = Face::Right;
     ^~~~
./src/player.hpp:49:1: error: expected declaration before ‘}’ token
 };
 ^
In file included from ./src/playercontroller.cpp:3:0:
./src/player.hpp:3:1: error: version control conflict marker in file
 <<<<<<< HEAD
 ^~~~~~~
In file included from ./src/playercontroller.cpp:3:0:
./src/player.hpp:6:1: error: version control conflict marker in file
 =======
 ^~~~~~~
In file included from ./src/playstate.hpp:4:0,
                 from ./src/playstate.cpp:1:
./src/map.hpp:43:1: error: version control conflict marker in file
 <<<<<<< HEAD
 ^~~~~~~
./src/map.hpp: In member function ‘Physics& Map::physics()’:
./src/map.hpp:32:30: error: ‘ThePhysics’ was not declared in this scope
  Physics &physics() { return ThePhysics; }
                              ^~~~~~~~~~
./src/map.hpp: In member function ‘PlayerController& Map::player1()’:
./src/map.hpp:34:42: error: ‘Player1Controller’ was not declared in this scope
     PlayerController &player1() { return Player1Controller; }
                                          ^~~~~~~~~~~~~~~~~
./src/map.hpp: In member function ‘PlayerController& Map::player2()’:
./src/map.hpp:35:42: error: ‘Player2Controller’ was not declared in this scope
     PlayerController &player2() { return Player2Controller; }
                                          ^~~~~~~~~~~~~~~~~
./src/map.hpp: At global scope:
./src/map.hpp:45:1: error: version control conflict marker in file
 =======
 ^~~~~~~
./src/map.hpp:49:22: error: no matching function for call to ‘PlayerController::PlayerController()’
     PlayerController Player1Controller, Player2Controller;
                      ^~~~~~~~~~~~~~~~~
In file included from ./src/map.hpp:13:0,
                 from ./src/playstate.hpp:4,
                 from ./src/playstate.cpp:1:
./src/playercontroller.hpp:11:5: note: candidate: PlayerController::PlayerController(GameWindow&)
     PlayerController(GameWindow &input);
     ^~~~~~~~~~~~~~~~
./src/playercontroller.hpp:11:5: note:   candidate expects 1 argument, 0 provided
In file included from ./src/playstate.hpp:4:0,
                 from ./src/playstate.cpp:1:
./src/map.hpp:49:41: error: no matching function for call to ‘PlayerController::PlayerController()’
     PlayerController Player1Controller, Player2Controller;
                                         ^~~~~~~~~~~~~~~~~
In file included from ./src/map.hpp:13:0,
                 from ./src/playstate.hpp:4,
                 from ./src/playstate.cpp:1:
./src/playercontroller.hpp:11:5: note: candidate: PlayerController::PlayerController(GameWindow&)
     PlayerController(GameWindow &input);
     ^~~~~~~~~~~~~~~~
./src/playercontroller.hpp:11:5: note:   candidate expects 1 argument, 0 provided
In file included from ./src/playstate.hpp:4:0,
                 from ./src/playstate.cpp:1:
./src/map.hpp:50:1: error: expected declaration before ‘}’ token
 };
 ^
