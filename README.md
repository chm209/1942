# 1942

```
* 1942 ゲーム開発
* 期間: 2022.03.12 ~ 2022.05.30
* 環境: Windows 10 cmd
* 開発ツール: Visual Studio 2019, MySQL@5.7.37 Shell 
* 言語: C言語、韓国語
```

## 主題

```
* 1942ゲームをmudゲームで一部開発
```

## 目的
```
* 課題
*　C言語の勉強
```

# プロジェクト

```
* ログイン
* 会員登録
* ランキング
* ショップ
    - ゲームポイントを利用して、ゲム内でアイテムと効果アイテムを購入
    - ランキング画面で確認できる効果アイテム
    - 購入、販売機能
* ゲーム
    - ユーザの動き、攻撃、爆誕機能
    - 敵の生成、攻撃、動きパータン
    - アイテムの生成と効果
```

## DB

|  user  |              |      |        |
| :----: | :----------: | :--: | :----: |
| Field  |     Type     | Null |  Key   |
|   id   | varchar2(50) |  no  | PK |
| passwd | varchar2(50) |  no  |        |
| score  |   int(11)    | yes  |        |
| point  |   int(11)    | yes  |        |

| item_list |              |      |                     |
| :-------: | :----------: | :--: | :-----------------: |
|   Field   |     Type     | Null |         Key         |
|    id     | varchar2(50) |  no  | FK (user -> id) |
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
|   id    | varchar2(50) |  no  | FK (user -> id) |
|  score  |   int(11)    | yes  |                     |
|  item1  |   int(11)    | yes  |                     |
|  item2  |   int(11)    | yes  |                     |
|  item3  |   int(11)    | yes  |                     |
|  item4  |   int(11)    | yes  |                     |

## 빌드 전

```
* x64, Debug buildを維持すること
```

## License

##### GNU General Public License v3.0

##### Copyright 2022 chm209 all right reserved
