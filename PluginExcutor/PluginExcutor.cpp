#include "PluginExcutor.h"
#include "PluginExcutor.h"
#include <object_model/Turn.h>
#include <object_model/ActorFactory.h>

#ifdef WIN32
#pragma comment(lib,"plugin_framework.lib")
#endif // win32




void PluginExcutor::__run()
{
	PluginManager & pm = PluginManager::getInstance();
	const PluginManager::RegistrationMap & rm = pm.getRegistrationMap();
	for (PluginManager::RegistrationMap::const_iterator itor = rm.begin(); itor != rm.end(); itor++)
	{
		PluginTypes_.push_back(itor->first);
	}

	for (PluginTypeVec::iterator iter = PluginTypes_.begin(); iter != PluginTypes_.end(); iter++)
	{
		std::cout << iter->c_str() << std::endl;
	}

	ActorInfo ai;
	for (apr_size_t i = 0; i < PluginTypes_.size(); i++)
	{
		const std::string & key = PluginTypes_[i];
		const PF_RegisterParams & rp = rm.find(key)->second;
		// Create it
		IActor * plugin = ActorFactory::createActor(key);
		plugin->getInitialInfo(&ai);
		ai.id += 1;
		actors_.insert(std::make_pair(plugin, ai));

	}

	ActorInfo * p = NULL;
	Turn t;
	for (ActorMap::iterator it = actors_.begin(); it != actors_.end(); ++it)
	{
		t.self = &(it->second);
		it->first->play(&t);
	}

}


