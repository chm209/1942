# 1942

```
* 1942 게임 개발 저장소
* 기간: 2022.03.12 ~ 2022.05.30
* 환경: Windows 10 cmd
* 개발 툴: Visual Studio 2019, MySQL@5.7.37 Shell 
* 사용언어: C언어
```

## 주제

```
* 1942 슈팅 게임을 cmd 머드 게임으로 구현한다.
```

## 목적
```
* C 언어와 MySQL을 능숙하게 사용할 수 있는지 프로젝트를 진행하여 판단한다.
* 소스코드 분석 보고서를 작성하여 소스코드를 100% 이해하고 있는지 확인한다.
```

# 프로젝트 관련

## 구현완료
```
* 로그인 시스템
* 회원가입 시스템
* 랭킹 시스템
* 상점 시스템
    - 게임 포인트를 이용하여 인게임 아이템과 효과 아이템
    - 랭킹창에서 확인할 수 있는 효과 아이템
    - 구매, 판매 기능
* 게임
    - 유저 움직임, 공격, 폭탄 기능
    - 적군 생성, 공격, 움직임 패턴
    - 아이템 생성, 효과
```

## DB 테이블

|  user  |              |      |        |
| :----: | :----------: | :--: | :----: |
| Field  |     Type     | Null |  Key   |
|   id   | varchar2(50) |  no  | 기본키 |
| passwd | varchar2(50) |  no  |        |
| score  |   int(11)    | yes  |        |
| point  |   int(11)    | yes  |        |

| item_list |              |      |                     |
| :-------: | :----------: | :--: | :-----------------: |
|   Field   |     Type     | Null |         Key         |
|    id     | varchar2(50) |  no  | 외부키 (user -> id) |
|   item1   |   int(11)    | yes  |                     |
|   item2   |   int(11)    | yes  |                     |
|   item3   |   int(11)    | yes  |                     |
|   item4   |   int(11)    | yes  |                     |
|   item5   |   int(11)    | yes  |                     |
|   item6   |   int(11)    | yes  |                     |
|   item7   |   int(11)    | yes  |                     |
|   item8   |   int(11)    | yes  |                     |
|   item9   |   int(11)    | yes  |                     |
|  item10   |   int(11)    | yes  |                     |

| ranking |              |      |                     |
| :-----: | :----------: | :--: | :-----------------: |
|  Field  |     Type     | Null |         Key         |
|   id    | varchar2(50) |  no  | 외부키 (user -> id) |
|  score  |   int(11)    | yes  |                     |
|  item1  |   int(11)    | yes  |                     |
|  item2  |   int(11)    | yes  |                     |
|  item3  |   int(11)    | yes  |                     |
|  item4  |   int(11)    | yes  |                     |

## 빌드 전

```
* MySQL 버전을 맞춰서 DB 테이블을 구성
* x64, 디버그 빌드를 유지
```

## License

##### GNU General Public License v3.0

##### Copyright 2022 chm209 all right reserved