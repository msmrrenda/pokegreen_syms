// <meta charset="utf-8"> 
// ↑Content-Typeに指定したcharsetを無視するブラウザ対策
#ifndef MEMORY_STRUCT_H
#define STRUCT_SIZE (3808)
#define MEMORY_STRUCT_H

// dummyXXXX は現在のところ把握できていない領域です
//
// 戦闘中のメモ
// CD0F- 出したポケモンのレベル/最大HP/Atk/Def/Spd/Spc/各種能力変化ランク
// CD23- 相手の？ポケモンのレベル/最大HP/Atk/Def/Spd/Spc/各種能力変化ランク
// D003-6: 戦闘中/技1-4
// D014-7: 戦闘中/PP1-4
// D037: おじいさん戦フラグ
// D092: カーソルのある技/テンポラリ領域
// D0BE: 技名バッファ/ステータス見ると変わる
// D0B9: 技1-4/ステータス見ると変わる
// D0E1: 捕まえた種族/ここが0以外のときに道具を使うと戦闘強制終了
// D0E3: カーソルのある技/ステータス名では1ページ目:図鑑no, 2ページ目: 内部no
//
// D11D: 主人公の名前
struct memory_struct {
	unsigned char dummyD120[3];
	// D123
	unsigned char count; // 手持ちの数
	unsigned char name[7]; // 手持ち全員の種族一覧
	// D12B
	struct{
		unsigned char name; // 種族 0
		unsigned char current_hp[2]; // 現在HP 1
		unsigned char box_level; // 預けレベル 3
		unsigned char status; // 状態フラグ 4
		unsigned char type[2]; // タイプ 5
		unsigned char item; // 初代のレア度 金銀の持ち物 7
		unsigned char waza[4]; // わざ 8
		unsigned char trainerid[2]; // ID 12
		unsigned char exp[3]; // 経験値 14
		unsigned char hp_exp[2]; // HP努力値 17
		unsigned char atk_exp[2]; // 攻撃努力値 19
		unsigned char def_exp[2]; // 防御努力値 21
		unsigned char spd_exp[2]; // 素早さ努力値 23
		unsigned char spc_exp[2]; // 特殊努力値 25
		unsigned char ab_pot; // AB個体値 27
		unsigned char sc_pot; // SC個体値 28
		unsigned char pp[4]; // 上位2bitはポイントアップ使用回数 下位6bitが実際のPP 29
		unsigned char level; // 33
		unsigned char max_hp[2]; // 最大HP 34
		unsigned char atk[2]; // 攻撃 36
		unsigned char def[2]; // 防御 38
		unsigned char spd[2]; // 素早さ 40
		unsigned char spc[2]; // 特殊 42
		// size: 44
	} poke[6];
	// D233
	struct {
		unsigned char name[6]; // おやの名前
	} oya[6];
	// D257
	struct {
		unsigned char name[6]; // ニックネーム
	} nickname[6];
	unsigned char pokedex_caught[19]; // D27B: つかまえたフラグ 下位bitから図鑑No順
	unsigned char pokedex_found[19]; // D28E: みつけたフラグ 下位bitから図鑑No順
	// D2A1
	struct {
		unsigned char count; // D2A1: アイテムの所持数(種類)
		struct{
			unsigned char type; // D2A2 + 2n: アイテムの種類
			unsigned char count; // D2A3 + 2n: アイテムの個数
		} item[20];
		unsigned char terminate; // D2CA: 0xFFが入る分
	} item_data;
	
	unsigned char money[3]; // D2CB: 所持金　BCDで保管されている
	unsigned char rivalname[6]; // D2CE: ライバルのなまえ
	unsigned char config; // D2D4: せっていフラグ
	unsigned char badge_flag; // D2D5: バッジ所持
	unsigned char dummyD2D6;
	unsigned char dummyD2D7; // 普段0x01 入力まちだと0x03
	unsigned char playerID[2]; // D2D8: IDno.
	unsigned char BGMno; // D2DA: 現在のマップのBGM番号、自転車や波乗り終了時に戻すための値だと思う
	unsigned char BGMbank; // D2DB: 現在のマップのBGMバンク番号
	unsigned char color_pattern; // D2DC: 画面の色パターン 上位4bit: 背景の色 下位bit: 主人公の色
	unsigned char mapID; // D2DD マップ番号 テレポート先と同様
	unsigned char maptileNo[2]; // D2DE:
	// 道具の31番目 2x2のタイルで計算した座標(横移動は+1、縦移動は+横幅分
	// 当たり判定や「本来の場所」の判定に使っている
	
	unsigned char playerY; // D2E0: マップ中のY座標
	unsigned char playerX; // D2E1: マップ中のX座標
	unsigned char tileoffsetY; // D2E2: 2x2タイル中のY座標
	unsigned char tileoffsetX; // D2E3: 2x2タイル中のX座標
	unsigned char outer_mapNo; // D2E4: 屋内にいるとき: 屋外のマップID
	unsigned char dummyD2E5[6];
	unsigned char npc_msg_offset[2]; // D2EB: 会話データテーブルのオフセット
	unsigned char map_event_offset[2]; // D2ED: マップにいるときここに毎フレーム jp する
	unsigned char dummyD2EF[458];
	// D2EF: 屋外マップ 隣のマップがある方向フラグ(1:右,2:左,4:下,8:上)
	// D2F0: 屋外マップ 上のマップID
	// D2FB: 屋外マップ 下のマップID
	// D306: 屋外マップ 左のマップID
	// D311: 屋外マップ 右のマップID
	// D32D: 出口の数
	// D32E: 出口1縦座標
	// D32F: 出口1横座標
	// D330: 行先出口ID
	// D331: mapID FFだと今いるのと同一の街？ -> D2E4に記録されているマップ

	// D4B9 じぶんのパソコン
	struct {
		unsigned char count; // アイテムの所持数(種類)
		struct{
			unsigned char type; // アイテムの種類
			unsigned char count; // アイテムの個数
		} item[50];
		unsigned char terminate;
	} pc_item_data;

	// D51F
	unsigned char dummyD51F;
	unsigned char dummyD520[3];
	unsigned char coin[2]; // D523: ゲームコーナーのコイン枚数
	unsigned char dummyD525[8];
	// D52D
	unsigned char flagD52D; // 0x20 イーブイ
	// D52E
	unsigned char dummyD52E[337];  // 353 - 337 - 1
	unsigned char flagD67F; // 自転車 0x01: 倍速移動 0x02: 倍速解除
	unsigned char dummyD680[10];
	unsigned char fly_flags[2]; // D68A-D68B 空を飛ぶフラグ
	unsigned char dummyD68C[2];
	// D68E
	unsigned char kaseki_item_id; // 化石のアイテム番号
	unsigned char kaseki_id; // 化石のポケモン番号
	// D690
	unsigned char dummyD690[3]; 
	unsigned char jump_counter; //D693 ジャンプ中のカウント　10以上を入れて段差を飛ぶと壁抜け
	unsigned char dummyD694[4]; 
	unsigned char teleport; //D698  テレポートの行先
	unsigned char last_fly; //D699  最後にそらをとぶで飛んだ先
	unsigned char dummyD69A[27]; 
	// D6AD bit7setで通信
	// D6B1 bit3setで離陸する
	// D6B5
	unsigned char flagD6B5; // 移動方式フラグ 0x80:くるくる 0x40: 跳ねる
	unsigned char dummyD6B6[108];
	// D6CA bit5図鑑らしい
	// D722
	unsigned char flagD722; // 0x01:化石あずけた 0x03:もうちょっと時間かかる

	unsigned char dummyD723[229]; //249
	struct {
		unsigned char name;
		unsigned char level;
	} wild_encount_table[10]; // D808-D81B エンカウントテーブル

	unsigned char dummyD81C[353];
	unsigned char playtime_hour;  // D97D プレイ時間 時
	unsigned char dummyD97E;
	unsigned char playtime_min;   // プレイ時間 分
	unsigned char playtime_sec;   // プレイ時間 秒
	unsigned char playtime_frame; // プレイ時間 1/60秒
	unsigned char dummyD982;
	unsigned char dummyD983;
	unsigned char dummyD984;
	// D985 育てや
	struct {
		struct{
			unsigned char name[6];
		} nickname;
		struct{
			unsigned char oya[6];
		} oya;
		struct{
			unsigned char name; // 種族
			unsigned char current_hp[2]; // 現在HP
			unsigned char box_level; // 引き取りレベル
			unsigned char status; // 状態フラグ
			unsigned char type[2]; // タイプ
			unsigned char item; // 初代のレア度 金銀の持ち物
			unsigned char waza[4]; // わざ
			unsigned char trainerid[2]; // ID
			unsigned char exp[3]; // 経験値
			unsigned char hp_exp[2]; // HP努力値
			unsigned char atk_exp[2]; // 攻撃努力値
			unsigned char def_exp[2]; // 防御努力値
			unsigned char spd_exp[2]; // 素早さ努力値
			unsigned char spc_exp[2]; // 特殊努力値
			unsigned char ab_pot; // AB個体値
			unsigned char sc_pot; // SC個体値
			unsigned char pp[4];
		} poke;
	} sodateya;
	// D9B2
	struct {
		unsigned char count; // 選択中のボックスに入っているポケモンの数
		unsigned char name[31]; // 選択中のボックスに入ってるポケモンの見かけの種別
		struct { // D9D2
			unsigned char name; // ポケモンの中身の種別
			unsigned char current_hp[2]; // HP現在値
			unsigned char level; // レベル
			unsigned char status; // ステータス異常フラグ
			unsigned char type[2]; // タイプ
			unsigned char item; // 持ち物
			unsigned char waza[4]; // 技
			unsigned char trainerid[2]; // ID
			unsigned char exp[3]; // 経験値
			unsigned char hp_exp[2]; // HP努力値
			unsigned char atk_exp[2]; // 攻撃努力値
			unsigned char def_exp[2]; // 防御努力値
			unsigned char spd_exp[2]; // 素早さ努力値
			unsigned char spc_exp[2]; // 特殊努力値
			unsigned char ab_pot; // AB個体値
			unsigned char sc_pot; // SC個体値
			unsigned char pp[4]; // PP
		} poke[30];
		struct { // DDB0
			unsigned char name[6]; // 選択中のボックスに入ってるポケモンの親名
		} oya[30];
		struct { // DE64
			unsigned char name[6]; // 選択中のボックスに入ってるポケモンのニックネーム
		} nickname[30];
	} box;

	// DF18
	unsigned char dummyDF18[232];
};

// 以下、メモ
//  状態フラグ
//   下3bit: ねむり 同時に残ターン数も示す
//   4bit目: どく
//   5bit目: やけど
//   6bit目: こおり
//   7bit目: まひ
//   8bit目: 未使用 ポケセンで回復する、戦闘開始時のボールは黒くなる、表記上は「ふつう」
//  設定フラグ
//   下4bit: はなしのはやさ　0001:はやい 0011:ふつう 0101: おそい
//   7bit目: 戦闘タイプ 0: いれかえ 1:かちぬき
//   8bit目: 戦闘アニメ 0: みる 1:みない
//   話の速さはウェイトをかける時間の模様。0000にすると一瞬で全部表示。
//   ただし不正な値が指定されているとせっていを開いた瞬間に0011にリセットされてしまう
//   5-6bit目は未使用なんだろうか。 ->ピカ版ではサウンドタイプ
//
//   空を飛ぶフラグ
//   D68A
//     01: マサラ(立ってないと暴走)
//   D68B
//     01: グレン
//     02: セキエイ
//     04: ヤマブキ
//
//  テレポート先
//     00: マサラ 01: トキワ ・・・ 08: グレン 09: セキエイ 0A: ヤマブキ
//     0B: 暴走
//     0C: (1番道路) 0D: (2番道路) 0E: (3番道路) 0F: おつきみ山前(4番道路)
//     10: (5番道路) 11: (6番道路) 12: (7番道路) 13: (8番道路) 14: (9番道路) 15: イワヤマ前(10番道路)
//	   16: (11番道路) 17: (12番道路) 18: (13番道路) 19: (14番道路) 1A: (15番道路)
//	   1B: (16番道路) 1C: (17番道路) 1D: (18番道路) 1E: (19番水道) 1F: (20番水道)
//	   20: (21番水道) 21: (22番道路) 22: (23番道路) 23: (24番道路) 24: (25番道路)
//	   25-27: (マサラ民家) 28: (オーキド研) 29-2A: (トキワポケセン) 2B-2C: (トキワ民家) 2D: (トキワジム)
//	   2E: (ディグダの穴) 2F,31: (2番道路ゲート) 30,32: (2番道路民家？) 33: (トキワの森)
//	   34: (ニビ民家)
//	   EC: シルフほんしゃビル ED-EE: 暴走 EF-F0: (リーグ本部/BGMタマムシ) F1-FF: 暴走(たぶん)
#endif
