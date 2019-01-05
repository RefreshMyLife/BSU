USE MilitaryUnit

--вывести призывников

SELECT [Soldiers].[ID]
	,[Soldiers].[Name]
	,[Soldiers].[Surname]	
	,[Rank].[NameOfRank]
FROM [Soldiers], [Rank]
WHERE [Soldiers].[RankID] = [Rank].[ID] 
	AND [Soldiers].[FormOfServiceID] = 1
ORDER BY [Soldiers].[RankID] DESC