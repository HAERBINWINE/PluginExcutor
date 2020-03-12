#pragma once
#include <list>
#include<map>
#include <boost/shared_ptr.hpp>
#include <plugin_framework/PluginManager.h>
#include <object_model/object_model.h>
#include <iostream>

class PluginExcutor
{

	typedef std::pair<apr_int32_t, apr_int32_t> Location;
	typedef std::vector<std::string> PluginTypeVec;
	typedef std::map<IActor *, ActorInfo> ActorMap;
	typedef std::list<ActorInfo *> Faction;
public:
	static PluginExcutor & GetInstance()//Singleton
	{
		static PluginExcutor pe;
		return pe;

	}
	void start()// Entry
	{
		__run();
	}


private://构造函数私有
	PluginExcutor()
	{

	}
	~PluginExcutor()
	{

	}
	PluginExcutor(const PluginExcutor & c) = delete;
	void __run();

private:
	bool isFinished;
	Faction pluginfaction_;

	ActorMap actors_;
	PluginTypeVec PluginTypes_;
};

