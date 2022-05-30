# BTL-Cuoi-Ki-Pong
1. Hướng dẫn cài đặt:

Nếu đọc hướng dẫn và chưa hiểu thì có thể tham khảo vid sau về cách cài SFML về máy: https://www.youtube.com/watch?v=G5-8Tcz6WaU

Bước 1: Cài Code::Blocks:

• Truy cập và làm theo hướng dẫn đường link này để tải và cài đặt Code::Blocks (nếu chưa có Code::Blocks): https://quantrimang.com/cach-tai-va-cai-dat-code-block-tren-windows-10-179163

Bước 2: Cài Cmake:

• Nếu đã có Code::Blocks trên máy thì việc tiếp theo cần làm là cài Cmake. Vì SFML yêu cầu compiler của IDE và bản builds phải giống nhau 100% mới chạy được, mà 

Code::Blocks phiên bản mới nhất (20.03) sử dụng compiler version 8.1.0, 32/64 bit trong khi các bản pre-built của SFML không có bản nào tương thích với version 8.1.0. 

Vì vậy cần Cmake để tự build file SFML mới có thể tương thích với Code::Blocks.

• Truy cập đường link sau: https://cmake.org/download/

• Tìm xuống phần Latest Release, kéo xuống phần Binary distributions và tìm thư mục phù hợp với máy tính (như máy tính 32 bits hay 64 bits, sử dụng Windows, Mac hay 

Linux).
• Sau khi tải và cài đặt xong Cmake, vào phần thanh Search ở Taskbar trên màn hình, tìm Cmake gui.

• Mở Cmake gui.

Bước 3: Cài SFML:

• Truy cập đường link sau: https://www.sfml-dev.org/download/sfml/2.5.1/

• Kéo xuống dưới đến khi gặp dòng Source code và ấn download.

• Giải nén folder và cho vào vị trí bạn muốn.

• Sau khi có Cmake và folder Source code tải thành công, tạo 1 folder mới (để tên là gì cũng được, tuy vậy gợi ý để tên là SFML_Builds) và đây sẽ là folder tự build 

SFML.

• Trong Cmake, có 2 dòng trên đầu màn hình là Where is the source code (trích đường dẫn folder source code vừa tải từ SFML) và Where to build the binaries (trích đường 

dẫn folder SFML_Builds vừa tạo).

• Sau khi trích dẫn xong, ở phía dưới màn hình có 2 nút Configure và Generate. Ấn configure và khi Cmake hỏi sử dụng complier nào thì chọn CodeBlocks – MinGW 

Makefiles. Sau đó ấn finish và đợi để configure.

• Sau khi Cmake configure xong trên màn hình sẽ hiện 1 danh sách màu đỏ, tìm dòng SFML_BUILD_EXAMPLE và tích vào đó, và sau đó ấn configure, sau khi Cmake báo 

configuring done thì ấn generate và đợi máy báo generating done.

• Sau đó mở folder SFML_Builds và sẽ thấy có 1 file SFML.cbp. Mở file này bằng Code::Blocks và ở phần thanh công cụ có 1 nút hình bánh răng cưa (nút Build). Ấn vào đó 

và đợi cho đến khi nào Code::Blocks báo build thành công, sau đó thoát khỏi Code::Blocks.

• Vào Cmake, ở phần CMAKE_BUILD_TYPE xóa chữ Release và type debug (in thường hoặc hoa đều được). Sau đó ấn configure và generate như bước trên. Sau đó lại mở lại file 

SFML.cbp vừa nãy và tiếp tục ấn nút Build và đợi máy báo build thành công rồi lại thoát khỏi Code::Blocks.
 
• Vào Cmake, ở phần BUILD_SHARED_LIBS bỏ dấu tích. Sau đó ấn configure và generate như bước trên. Sau đó lại mở lại file SFML.cbp vừa nãy và tiếp tục ấn nút Build và 

đợi máy báo build thành công rồi lại thoát khỏi Code::Blocks.

• Vào Cmake, ở phần CMAKE_BUILD_TYPE xóa chữ debug và type release. Sau đó ấn configure và generate như bước trên. Sau đó lại mở lại file SFML.cbp vừa nãy và tiếp tục 

ấn nút Build và đợi máy báo build thành công rồi lại thoát khỏi Code::Blocks.

• Sau đó, tắt Cmake và clone repo về máy, sau đó mở file cbp lên. Chuột phải vào file project ở bên tay trái và chọn Build Options. Ở góc trên cùng tay trái ấn vào tên 

folder và vào mục Search directories:

- Ở phần compiler, link đường dẫn đến folder include của folder Source code SFML tải phía trên.

- Ở phần linker, link đường dẫn đến folder lib của folder SFML Builds phía trên.

• Sau đó thoát ra và chạy chương trình là được. Nếu trong trường hợp F9 báo lỗi “Undefined reference to 'SDL_main'” thì chỉ cần thêm “int argc, char* argv[]” vào trong int main() rồi F9 lại là được.

2. Mô tả trò chơi:

* Trò chơi tên là PONG, là trò chơi bóng bàn 2D dùng thanh chắn để không cho bóng lọt qua nền trái hoặc phải của màn hình.

* Nếu người chơi để bóng lọt qua thanh điều khiển thì người chơi còn lại được 1 điểm. Ai đến 5 điểm trước sẽ thắng.  

* Nếu đấu lẫn nhau, người chơi bên trái dùng phím W để di chuyển thanh lên và S để di chuyển thanh xuống, người chơi bên phải dùng phím Lên để di chuyển thanh lên và 
 Xuống để di chuyển thanh xuống.

* Nếu đấu với máy, người chơi dùng phím W để di chuyển thanh lên và S để di chuyển thanh xuống.

3. Mô tả chức năng đã cài đặt:

* Game được cài chế độ chơi với nhau và đấu với AI, thêm vào đó là 1 màn hình menu và chức năng Pause/Play.

* Ngoài ra game cũng có phần Tùy chỉnh để tăng giảm âm lượng, bật hoặc tắt chế độ Fullscreen, và tủy chình màu của thanh và bóng.

* Tất cả thao tác chọn lựa đều được thực hiện bằng chuột thay vì bàn phím.

* Link Youtube mô tả chức năng: https://www.youtube.com/watch?v=0fZ1foNK1wc

4. Các kĩ thuật lập trình được sử dụng:

a. Lớp: Lớp được sử dụng để khai báo 1 số nút và các biến sf::, các biến float và int, bool cũng được khai báo trong Lớp để dễ quản lý.

b. Enum: Việc sử dụng chuột để thao tác đòi hỏi thay vì dùng Lớp để tạo Menu và tương tác thì cần 1 cách khác dễ hiểu và dễ sử dụng hơn. Việc sử dụng Enum khiến cho việc di chuyển giữa các cửa sổ dễ hơn nhiều khi chỉ cần khai báo các States trong Enum là có thể di chuyển giữa các cửa sổ bằng If-else hoặc switch-case.

c. Mảng: Mảng được sử dụng để vẽ bảng điểm trong chế độ 1 người chơi và 2 người chơi. 

d. Cùng với đó là các kĩ thuật lập trình sử dụng các câu lệnh có sẵn của SFML nhằm giúp hiểu tương tác giữa bóng và màn, bóng và thanh, thanh và màn dễ hơn so với việc ngồi nháp và hình dung bằng toán thông thường.

Ví dụ: Thay vì viết rectangle.getPosition().y (lấy tọa độ y của thanh) thì có thể viết là retangle.getGlobalBound().top và có kết quả y hệt, tuy nhiên về lâu dài sẽ hiệu quả hơn khi phải kết hợp với các câu lệnh khác.

e. Đồ họa: Thêm phần Backgrround qua thư viện SFML/Graphics và âm thanh như tác động giữa thanh và bóng, bóng và màn hình, khi người chơi thắng,... qua thư viện SFML/Audio.

5. Kết luận: 

a. Từ việc học cách quản lý project, tách code thành các module qua các bài giảng của các thầy, em rất háo hức khi bắt tay vào làm project cuối kì này. Tuy vậy nó khó khăn hơn em tưởng khi mình phải tự bắt tay làm mọi thứ từ đầu, từ việc cài SFML (vì các hướng dẫn thông thường về việc cài SFML không tương thích với phiên bản mới) đến việc quản lý code, vì lúc này game không chỉ là 200-300 dòng code mà 2000 dòng nên sẽ khó quản lý hơn nhiều. May mắn thay là em đã chạy kịp Deadline và thành quả cuối cùng cũng khiến em khá hài lòng, tuy còn khá nhiều chỗ có thể refactor và nhiều tính năng mới có thể thêm vào.

b. Các điều tâm đắc rút được sau việc tạo chương trình này:

Code rất thú vị khi mình có 1 kế hoạch cụ thể cho nó, như việc lập pseudo code để hiểu cơ chế hoạt động của game, từ đó phát triển thành 1 mini game, đến khi hoàn thiện hoàn toàn game.

Việc sinh bug là không thể tránh khỏi trong quá trình làm game, vì vậy mình cần bình tĩnh, không vì thấy bug mà nản và sửa lung tung code vì làm như vậy sẽ càng khiến code thêm rối và thêm bug. Thay vào đó cần suy xét từng dòng code và cố phán đoán xem lỗi là gì và có hướng sửa hợp lý.

Khi code cần đặt tên khai báo biến, module và tạo các comment trong code để dễ dàng hiểu được những đoạn code khi mình đọc lại, vì số lượng dòng code mình phải làm việc cùng là lớn nên có thể mình sẽ không nhớ hết được từng dòng code chạy như nào. Do đó việc đặt tên hợp lý và dễ hiểu là vô cùng quan trọng.

c. Hướng phát triển: Với những điều vừa kể trên, em mong muốn được tiếp tục phát triển về mảng game, vì nó thú vị và phù hợp với lứa tuổi sinh viên như em. Ngoài ra em sẽ học thêm một số ngôn ngữ khác như Python để tạo được sự đa dạng trong việc lập trình, và có thể code game bằng các ngôn ngữ khác. 
