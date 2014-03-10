class Resource:
    def __init__(self, system_graph, name, tasks):
        """Constructs a resource that belongs to system (SystemGraph), that
           has a name and the tasks can obtain this resource"""
        self.system_graph = system_graph
        self.name = name
        self.subtasks = []
        for t in tasks:
            subtask = self.system_graph.get_subtask(t)
            assert subtask, "Subtask %s not found, that uses resource %s" % (t, name)
            self.subtasks.append(subtask)

        # Allocated by the PrioritySpreadingPass
        self.static_priority = None

    def __repr__(self):
        return "<Res %s pri:%s>" %(self.name, self.static_priority)
