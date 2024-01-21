#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_FLOORS 17
#define ROOMS_PER_FLOOR 12
#define MAX_PEOPLE_PER_ROOM 1
// khai báo room 
typedef struct {
    char name;
    char room[5];
} Guest;
// khai báo status
typedef struct {
    int status;
    Guest guest[MAX_PEOPLE_PER_ROOM];
} Room;
// định nghĩa struct hotell
typedef struct {
    Room floor[NUM_FLOORS][ROOMS_PER_FLOOR];
} Hotel;
// tạo hottel
void initHotel(Hotel *hotel) {
    for (int i = 0; i < NUM_FLOORS; i++) {
        for (int j = 0; j < ROOMS_PER_FLOOR; j++) {
            hotel->floor[i][j].status = 0;
        }
    }
}
// hàm xữ lí vấn đề 1 check in
int checkIn(Hotel *hotel, char name, char room[]) {
    for (int i = 0; i < NUM_FLOORS; i++) {
        for (int j = 0; j < ROOMS_PER_FLOOR; j++) {
            if (hotel->floor[i][j].status == 0) {
                hotel->floor[i][j].status = 1;
                hotel->floor[i][j].guest[0].name = name;
                strcpy(hotel->floor[i][j].guest[0].room, room);
                return 1;
            }
        }
    }
    return 0;
}
// hàm in ra thông tin phòng
void printRoomInfo(Hotel *hotel, char room[]) {
    for (int i = 0; i < NUM_FLOORS; i++) {
        for (int j = 0; j < ROOMS_PER_FLOOR; j++) {
            if (strcmp(hotel->floor[i][j].guest[0].room, room) == 0) {
                printf("Room: %s\n", hotel->floor[i][j].guest[0].room);
                printf("Guests:\n");
                for (int k = 0; k < MAX_PEOPLE_PER_ROOM; k++) {
                    printf("%c\n", hotel->floor[i][j].guest[k].name);
                }
                return;
            }
        }
    }
    printf("Room not found.\n");
}
// hàm thêm group vào phòng
void addGuestToGroup(Hotel *hotel, char name, char room[]) {
    for (int i = 0; i < NUM_FLOORS; i++) {
        for (int j = 0; j < ROOMS_PER_FLOOR; j++) {
            if (strcmp(hotel->floor[i][j].guest[0].room, room) == 0) {
                int k = 0;
                while (hotel->floor[i][j].guest[k].name != '\0') {
                    k++;
                }
                hotel->floor[i][j].guest[k].name = name;
                strcpy(hotel->floor[i][j].guest[k].room, room);
                return;
            }
        }
    }
    printf("Room not found.\n");
}
// hàm xóa khách ra khỏi căn phòng
void removeGuestFromGroup(Hotel *hotel, char room[]) {
    for (int i = 0; i < NUM_FLOORS; i++) {
        for (int j = 0; j < ROOMS_PER_FLOOR; j++) {
            if (strcmp(hotel->floor[i][j].guest[0].room, room) == 0) {
                hotel->floor[i][j].status = 0;
                for (int k = 0; k < MAX_PEOPLE_PER_ROOM; k++) {
                    hotel->floor[i][j].guest[k].name = '\0';
                    strcpy(hotel->floor[i][j].guest[k].room, "");
                }
                return;
            }
        }
    }
    printf("Room not found.\n");
}
// đặt trạng trái của phòng nếu trạng thái phòng tồn taijnguoiwf thì in ra tên khach
void printHotelStatus(Hotel *hotel) {
    for (int i = 0; i < NUM_FLOORS; i++) {
        printf("Floor %d:\n", i);
        for (int j = 0; j < ROOMS_PER_FLOOR; j++) {
            printf("Room %s: ", hotel->floor[i][j].guest[0].room);
            if (hotel->floor[i][j].status == 0) {
                printf("Empty\n");
            } else {
                for (int k = 0; k < MAX_PEOPLE_PER_ROOM; k++) {
                    printf("%c ", hotel->floor[i][j].guest[k].name);
                }
                printf("\n");
            }
        }
        printf("\n");
    }
}

int main() {
    Hotel hotel;
    initHotel(&hotel);

    checkIn(&hotel, 'A', "P0.0");
    checkIn(&hotel, 'B', "P0.1");
    checkIn(&hotel, 'S', "P0.2");
    checkIn(&hotel, 'E', "P0.3");
    checkIn(&hotel, 'F', "P0.4");
    checkIn(&hotel, 'J', "P0.5");
    checkIn(&hotel, 'K', "P0.6");
    checkIn(&hotel, 'L', "P0.7");
    checkIn(&hotel, 'S', "P0.8");
    checkIn(&hotel, 'W', "P0.9");
    checkIn(&hotel, 'Q', "P0.10");
    checkIn(&hotel, 'A', "P0.11");

    checkIn(&hotel, 'T', "P1.0");
    checkIn(&hotel, 'M', "P1.1");
    checkIn(&hotel, 'K', "P1.2");
    checkIn(&hotel, 'L', "P1.3");
    checkIn(&hotel, 'J', "P1.4");
    checkIn(&hotel, 'S', "P1.5");
    checkIn(&hotel, 'A', "P1.6");
    checkIn(&hotel, 'Q', "P1.7");
    checkIn(&hotel, 'C', "P1.8");
    checkIn(&hotel, 'S', "P1.9");

    checkIn(&hotel, 'H', "P2.0");
    checkIn(&hotel, 'J', "P2.1");
    checkIn(&hotel, 'S', "P2.2");
    checkIn(&hotel, 'S', "P2.3");
    checkIn(&hotel, 'A', "P2.4");
    checkIn(&hotel, 'S', "P2.5");
    checkIn(&hotel, 'M', "P2.6");
    checkIn(&hotel, 'Q', "P2.7");
    checkIn(&hotel, 'D', "P2.8");

    // Thêm các khách mới vào đoàn tương ứng
    addGuestToGroup(&hotel, 'S', "P2.5");
    addGuestToGroup(&hotel, 'M', "P2.5");
    addGuestToGroup(&hotel, 'Q', "P2.5");
    addGuestToGroup(&hotel, 'D', "P2.5");

    // Kiểm tra thông tin của một đoàn bằng cách nhập địa chỉ phòng của trưởng đoàn
    printf("Enter room address: ");
    char roomAddress[5];
    scanf("%s", roomAddress);
    printRoomInfo(&hotel, roomAddress);

    // Xóa một đoàn khách
    removeGuestFromGroup(&hotel, "P2.5");

    // Kiểm tra lại thông tin của đoàn sau khi xóa
    printf("Enter room address: ");
    scanf("%s", roomAddress);
    printRoomInfo(&hotel, roomAddress);

    // In trạng thái hiện tại của khách sạn
    printf("Hotel status:\n");
    printHotelStatus(&hotel);

    return 0;
}