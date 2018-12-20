#include "CSpreadSheet.h" 
int main()
{
	/*
	// 新建Excel文件名及路径，TestSheet为内部表名
CSpreadSheet SS("D:\\Almh\\study\\project\\cloudeclc\\data\\512_16\\test.xls", "TestSheet");

CStringArray sampleArray, testRow;

SS.BeginTransaction();

// 加入标题
sampleArray.RemoveAll();
sampleArray.Add("姓名");
sampleArray.Add("年龄");
SS.AddHeaders(sampleArray);

// 加入数据
CString strName[] = {"徐景周","徐志慧","郭徽","牛英俊","朱小鹏"};
CString strAge[] = {"27","23","28","27","26"};
for(int i = 0; i < sizeof(strName)/sizeof(CString); i++)
{
sampleArray.RemoveAll();
sampleArray.Add(strName[i]);
sampleArray.Add(strAge[i]);
SS.AddRow(sampleArray);
}

SS.Commit();
*/
CSpreadSheet SS("D:\\Almh\\study\\project\\cloudeclc\\data\\512_16\\test.xls", "TestSheet");

CStringArray Rows, Column;

//清空列表框
m_AccessList.ResetContent();
for (int i = 1; i <= SS.GetTotalRows(); i++)
{
// 读取一行
SS.ReadRow(Rows, i);
CString strContents = "";
for (int j = 1; j <= Rows.GetSize(); j++)
{
if(j == 1)
strContents = Rows.GetAt(j-1);
else
strContents = strContents + " --> " + Rows.GetAt(j-1);
}

m_AccessList.AddString(strContents);
}
	return 0;
 } 


