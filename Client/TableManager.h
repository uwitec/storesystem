#pragma once
#include "StdAfx.h"
#include "LogManager.h"
#include "MainWidget.h"
class TableManager
{
public:
	TableManager(void);
	virtual ~TableManager(void);
	void setGui(MainWidget* pGui){ m_pGui = pGui; }
	template<typename T>
	T find(std::vector<T>& tableList,
		int32 id, int32& row);
protected:
	MainWidget* m_pGui;
	Log* m_pLog;
};

template<typename T>
T TableManager::find(std::vector<T>& tableList, int32 id, int32& row)
{
	if( tableList.size() <= 3 )
	{
		int32 size = tableList.size();
		for( int32 i = 0; i < size; ++i )
		{
			if( tableList[i]->id == id )
			{
				row = i;
				return tableList[i];
			}
		}
	}
	else
	{
		uint32 left = 0;
		uint32 right = tableList.size() - 1;
		if( tableList[left]->id == id )
		{
			row = left;
			return tableList[left];
		}
		if( tableList[right]->id == id )
		{
			row = right;			
			return tableList[right];
		}
		uint32 mid = (left + right) / 2;
		while( right - left > 1 )
		{
			uint32 midId = tableList[mid]->id;
			if( midId == id )
			{
				row = mid;
				return tableList[mid];
			}
			if( midId < id )
				left = mid;
			else
				right = mid;
			mid = (left + right) / 2;
		}
	}
	return 0;
}