/*
��蕶
�C���J�́A�V�N�ɒ��� 19 �̕����� s ���󂯎��܂����B
������ s �̌`���� [�p������ 5 ����],[�p������ 7 ����],[�p������ 5 ����] �ŕ\����܂��B
�C���J�́A�J���}�ŋ�؂�ꂽ������ s ���A�X�y�[�X�ŋ�؂�ꂽ������ɕϊ��������Ǝv���Ă��܂��B
�C���J�̑���ɁA���̏������s���v���O����������Ă��������B
*/

#include<iostream>
#include<vector>
#include<string>
#include<sstream>


//�s��
//getline()�̑�������stream�^�����󂯕t���Ȃ����Ƃ��������Ă����@�@std::string�ł͖����Ȃ̂ň�Ustd::stringstream ss(str)�ɑ������
//���̌����Ƃ��Ă������߁A�Ȃ�̂��߂�std::stringstream ss(str)�ɑ�������̂��킩�炸���������Ӗ��i�ł͂Ȃ�(�߂��Ⴍ����E�����ĂȂ񂩒m��񂯂ǗL�v�ȏ��𓾂�)�j���Ԃ�Q���
//����������R���X�g���N�^��������ł���(�R�s�y�R�[�h������킩��Ȃ�)
//���ƌl�I��std::vector<std::string> v�����߂Č��ā@v[0]=������@v[1]=������@v[2]=������@�c�@�Ƃ������̗����Ɏ��Ԃ���������
//���Ƃ������split�̑�������const�Ȃ̂������^��ł��邪�A���Ԃ�split�֐��ɓn������ύX�ł��Ȃ��悤�ɂƂ����Ǝv���i�K���j
//���ς�炸range_base for���̑��������ǂ�����o�Ă��Ă��邩�킩�炸�����������A�O�Ɉ�x����Ă����̂ŋL�����݂���킩����
//�����ς�炸range_base for�̑������͑������̃R���e�i�N���X�Ƃǂ������֘A������̂��킩��Ȃ�
//�悭���ʂ�for������range_base for�ɏ����������̎���range_base for �̑������ɓ����镶�������ʂ�for�Ɍ���Ȃ����߂ł���
//���Ȃ݂�getline���߂Ďg���܂���(��)




//�R�s�y�֐�(split)
//�撣���ăR�s�y���R�����g�Ő������Đ�������
//��������w��̕����ŋ�؂�@���́@�u100,200,300�v���J���}�ŋ�؂遨�@�o�́@�u100�v�@�u200�v�@�u300�v

std::vector<std::string> split(const std::string &str, char sep) {  //(������̐擪�̃|�C���^,��؂蕶��)�������Ɏ����Astd::vector<std::string>�^��Ԃ� split�ƌ����֐��@
	std::vector<std::string> v;     //�߂�l���i�[����vector
	std::stringstream ss(str);      //�X�g���[���̏������@�i�X�g���[�����ĉ��A�����̏������Ȃ�str���̂܂܎g���΂悢�̂ł́c�H�j
	std::string buffer;				//�o�b�t�@�i������^�j

	while (std::getline(ss, buffer, sep)) { //�������͕�����̒��o���ƂȂ���̓X�g���[���@�������͓��̓X�g���[�����璊�o���������̓ǂݍ��ݐ�ƂȂ镶����@��O�����s�̋�؂�L��
		v.push_back(buffer);                //std::vector<std::string>  v[0]=������@v[1]=������@V[2]=������@�Ƃ���vector 
	}

	return v;
}

int main() {
	std::string str1;	//��̕�����
	std::cin >> str1;   //������̓���
	for (const std::string &s : split(str1, ',')) {   //range_base for   ( �����o�͕�����̌^��ϐ��錾���Ă��邾�����Ďv���Ă܂��@�F�@split�֐���std::vector<std::string>�^�Ȃ̂�vector�Ƃ���range_base for ���g���� )
		std::cout << s << std::endl;
	}

	return 0;
}

