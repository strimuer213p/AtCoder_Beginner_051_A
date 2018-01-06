/*
問題文
イルカは、新年に長さ 19 の文字列 s を受け取りました。
文字列 s の形式は [英小文字 5 文字],[英小文字 7 文字],[英小文字 5 文字] で表されます。
イルカは、カンマで区切られた文字列 s を、スペースで区切られた文字列に変換したいと思っています。
イルカの代わりに、この処理を行うプログラムを作ってください。
*/

#include<iostream>
#include<vector>
#include<string>
#include<sstream>


//敗因
//getline()の第一引数がstream型しか受け付けないことを見逃していた　　std::stringでは無理なので一旦std::stringstream ss(str)に代入した
//この見落としていたため、なんのためにstd::stringstream ss(str)に代入したのかわからず混乱し無意味（ではない(めちゃくちゃ脱線してなんか知らんけど有益な情報を得た)）時間を浪費した
//しかもこれコンストラクタだったんですね(コピペコードだからわからない)
//あと個人的にstd::vector<std::string> vを初めて見て　v[0]=文字列　v[1]=文字列　v[2]=文字列　…　という事の理解に時間がかかった
//あとちょっとsplitの第一引数がconstなのか少し疑問であるが、たぶんsplit関数に渡したら変更できないようにとかだと思う（適当）
//相変わらずrange_base for文の第一引数がどこから出てきているかわからず混乱したが、前に一度やっていたので記事をみたらわかった
//が相変わらずrange_base forの第一引数は第二引数のコンテナクラスとどういう関連があるのかわからない
//よく普通のfor文からrange_base forに書き換える例の時にrange_base for の第一引数に当たる文字が普通のforに現れないためである
//ちなみにgetline初めて使いました(完)




//コピペ関数(split)
//頑張ってコピペをコメントで説明して生きたい
//文字列を指定の文字で区切る　入力　「100,200,300」→カンマで区切る→　出力　「100」　「200」　「300」

std::vector<std::string> split(const std::string &str, char sep) {  //(文字列の先頭のポインタ,区切り文字)を引数に持ち、std::vector<std::string>型を返す splitと言う関数　
	std::vector<std::string> v;     //戻り値を格納するvector
	std::stringstream ss(str);      //ストリームの初期化　（ストリームって何、ただの初期化ならstrそのまま使えばよいのでは…？）
	std::string buffer;				//バッファ（文字列型）

	while (std::getline(ss, buffer, sep)) { //第一引数は文字列の抽出元となる入力ストリーム　第二引数は入力ストリームから抽出した文字の読み込み先となる文字列　第三引数行の区切り記号
		v.push_back(buffer);                //std::vector<std::string>  v[0]=文字列　v[1]=文字列　V[2]=文字列　というvector 
	}

	return v;
}

int main() {
	std::string str1;	//空の文字列
	std::cin >> str1;   //文字列の入力
	for (const std::string &s : split(str1, ',')) {   //range_base for   ( ただ出力文字列の型を変数宣言しているだけって思ってます　：　split関数はstd::vector<std::string>型なのでvectorとしてrange_base for が使える )
		std::cout << s << std::endl;
	}

	return 0;
}

